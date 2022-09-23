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

int consoleCode{};

// Convert the buffer to all uppercase.
void to_upper(char *buffer)
{
    for (int i = 0; buffer[i] != '\0'; i++)
        buffer[i] = toupper(buffer[i]);
}

// Flush the input buffer to prevent unwanted inputs.
void flushBuffer(char *buffer)
{
    for (int i = 0; i < 1024; i++)
        buffer[i] = '\0';
}

// Check if the client is connected.
bool clientConnected{false};

// A pointer to the client socket.
struct sockaddr_in *client;

// A pointer to serverTime
int* serverTime_ptr;
void server_time(int* Time)
{
    int minute, hour, second;
    int serverTime = time(NULL)- *Time;
    hour = serverTime / 3600;
    serverTime = serverTime % 3600;
    minute = serverTime / 60;
    second = serverTime % 60;
    std::cout << "Server time: "
              << std::setw(2) << std::setfill('0')  << hour << ":"
              << std::setw(2) << std::setfill('0')  << minute << ":" 
              << std::setw(2) << std::setfill('0')  << second << std::endl;
}

// The main function for the thread, it will write the data to the console and perform the necessary operations.
int threadProc(void *server)
{
    while (true)
    {
        std::string consoleInput;
        std::cout << "";
        std::getline(std::cin, consoleInput);
        if (consoleInput == "exit")
        {
            closesocket((SOCKET)server);
            WSACleanup();
        }
        else if (consoleInput == "restart")
        {
            consoleCode = 1;
            closesocket((SOCKET)server);
            WSACleanup();
        }
        else if (consoleInput == "clear")
        {
            system("cls");
            fflush(stdout);
            std::cout << "> ";
        }
        else if (consoleInput == "help")
        {
            std::cout << "clientip - show client ip" << std::endl;
            std::cout << "restart  - restart server" << std::endl;
            std::cout << "clear    - clear console" << std::endl;
            std::cout << "exit     - close server and exit program" << std::endl;
            std::cout << "help     - show this message" << std::endl;
            std::cout << "time     - show server time" << std::endl;
            std::cout << "> ";
        }
        else if (consoleInput == "clientip")
        {
            char *ip;
            if (clientConnected)
            {
                ip = inet_ntoa(client->sin_addr);
                std::cout << "Client IP: " << ip << "\n> ";
            }
            else
                std::cout << "No client connected."
                          << "\n> ";
        }
        else if (consoleInput == "time")
        {
            server_time(serverTime_ptr);
            std::cout << "> ";
        }
        else
        {
            std::cout << "Unknown command. Type \"help\" for a list of commands.\n> ";
        }
    }
}



int main()
{
    int serverTime = time(NULL);
    serverTime_ptr = &serverTime;
    // Flush stdin and stdout to assure that the console is clean.
    fflush(stdin);
    fflush(stdout);
    // Character Buffer
    char buffer[1024];
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

        //Receive and send data.
        if ((msg_len = recv(client, buffer, sizeof(buffer), 0)) > 0)
        {
            std::cout << "\b\b  \nMessage received: " << buffer << std::flush << std::endl;
            to_upper(buffer);
            send(client, buffer, msg_len, 0);
            std::cout << "Message sent: " << buffer << std::flush << " (UPPERCASE)"
                      << "\n\n";
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