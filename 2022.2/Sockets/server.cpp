/*************************************** SERVER-SIDE STEPS **************************************
| * 1. Initialize the socket library with WSAStartup() (Windows only)                           |
| * 2. Create a socket with socket()                                                            |
| * 3. Bind the socket to an IP address and port with bind()                                    |
| * 4. Enter the listening state with listen()                                                  |
| * 5. Accept a connection with accept()                                                        |
| * 6. Receive data with recv()                                                                 |
| * 7. Send data with send()                                                                    |
| * 8. Close the socket with closesocket()                                                      |
| * 9. Clean up the socket library with WSACleanup() (Windows only)                             |
*************************************************************************************************
| Notes:                                                                                        |
| Steps 5-8 are repeated for each client that connects to the server;                           |
| *                                                                                             |
| Steps 1-4 are repeated for each server that is created;                                       |
| *                                                                                             |
| Server must be running before client can connect.                                             |
| *                                                                                             |
************************************************************************************************/

#undef UNICODE
#define _WIN32_WINNT 0x501
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <winsock2.h>

#include <ctime>
#include <vector>
#include <exception>
#include <sstream>
#include <iomanip>
#include <utility>
#include <iostream>
#include <algorithm>



int main()
{
    int serverTime = time(NULL);
    serverTime_ptr = &serverTime;
    // Flush stdin and stdout to assure that the console is clean.
    fflush(stdin);
    fflush(stdout);
    // Character Buffer
    char buffer[1024] = "Entre 2 e 3, qual o maior?";
    //--------------------------------- Initialize Winsock -----------------------------------
    WSADATA wsaData;
    int iResult;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0)
        printf("WSAStartup failed: %d\n", iResult);
    else
        printf("WSAStartup success: %d\n", iResult);

    //--------------------- Create a SOCKET for connecting to server --------------------------
    struct sockaddr_in saddr, caddr;
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(4002);

    int server = socket(AF_INET, SOCK_STREAM, 0);
    std::cout << ((server == -1) ? "Socket creation failed" : "Socket creation success") << std::endl;

    //--------------------------------- Bind the socket ---------------------------------------
    if (bind(server, (struct sockaddr *)&saddr, sizeof(saddr)) < 0)
        std::cout << "Bind failed" << std::endl;
    else
        std::cout << "Bind success" << std::endl;

    //------------------------- Listen for incoming connections -------------------------------
    listen(server, 5);
    if (server == SOCKET_ERROR)
        std::cout << "Listen failed" << std::endl;
    else
        std::cout << "Listen success" << std::endl;

    //---------------------- Create a thread to handle console input --------------------------
    if (CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)threadProc, (void *)server, 0, NULL) != NULL)
        std::cout << "Console thread created." << std::endl;
    else
        std::cout << "Console thread creation failed." << std::endl;

    //---------------------- Confirmation that the server is running ----------------------------
    std::cout << "\nServer initialized succesfully! Type \"help\" for a list of commands.\n";

    //--------------------------------- Accept a client ---------------------------------------

    // Client properties.
    int client, caddr_len = sizeof(caddr);
    int msg_len;
    while (true)
    {
        std::cout << "> ";
        // Accept a client
        client = accept(server, (struct sockaddr *)&caddr, &caddr_len);
        if (client == SOCKET_ERROR)
        {
            std::cout << "\b\bServer Closed." << std::endl;
            break;
        }
        else
            std::cout << "\b\b  \nAccept success; Client connected.\n> ";

        // Set the clientConnected flag to true.
        clientConnected = true;
        // Global client variable receives the client address, used for the clientip command.
        ::client = &caddr;

        // Send the message to the client.
        msg_len = send(client, buffer, sizeof(buffer), 0);

        // Receive and send data.
        if ((msg_len = recv(client, buffer, sizeof(buffer), 0)) > 0)
        {
            if(buffer_string(buffer) == "3")
            {
                char winMessage[1024] = "Voce acertou!";
                send(client, winMessage, sizeof(winMessage), 0);
            }
            else
            {
                char loseMessage[1024] = "Voce errou!";
                send(client, loseMessage, sizeof(loseMessage), 0);
            }
        }

        // Close the client socket and set the clientConnected flag to false.
        fflush(stdout);
        flushBuffer(buffer);
        closesocket(client);
        std::cout << "\b\bClient disconnected" << std::endl;
        clientConnected = false;
    }

    // Restart the server if the consoleCode is 1.
    if (consoleCode == 1)
    {
        std::cout << "\nRestarting...\n\n";

        consoleCode = 0;
        main();
    }
    return 0;
}