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

#include "ServerConsole.hpp"
void chat(void *cl);

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
    saddr.sin_port = htons(8922);

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
    if (thread_HANDLE = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)threadProc, (void *)server, 0, NULL) != NULL)
        std::cout << "Console thread created." << std::endl;
    else
        std::cout << "Console thread creation failed." << std::endl;

    //---------------------- Confirmation that the server is running ----------------------------
    std::cout << "\nServer initialized succesfully! Type \"help\" for a list of commands.\n";

    //--------------------------------- Accept a client ---------------------------------------

    // Client properties.
    std::vector<int> clients;
    int cliente, caddr_len = sizeof(caddr);
    int msg_len;
    int clientCount = 0;
    while (true)
    {
        std::cout << "> ";
        cliente = accept(server, (struct sockaddr *)&caddr, &caddr_len);
        if (cliente == SOCKET_ERROR)
            std::cout << "Accept failed" << std::endl;
        else
        {
            clients.push_back(cliente);
            std::cout << "Client Connected!" << std::endl;
            char buffauxiliar[1024] = "Connected to chat!\n";
            send(server, buffauxiliar, sizeof(buffauxiliar), 0);
            clientConnected = true;
            ::client = &caddr;
        }

        if (chatRequest)
        {
            for (int i = clientCount; i < clients.size(); i++)
            {
                HANDLE threadNum;
                std::cout << "Client " << i << " connected to chat." << std::endl;
                std::pair<int, HANDLE> *pair = new std::pair<int, HANDLE>(clients[i], threadNum);
                threadNum = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)chat, (void *)pair, 0, NULL);
                clientCount++;
            }
            closesocket(cliente);
        }
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

void chat(void *cl)
{
    char buffer[1024];
    int msg_len;
    std::pair<int, HANDLE> threadClient = *(std::pair<int, HANDLE> *)cl;
    std::cout << "Thread " << threadClient.second << " is running." << std::endl;
    while (chatRequest)
    {
        recv((SOCKET)threadClient.first, buffer, sizeof(buffer), 0);
        std::cout << "Client: " << buffer_string(buffer) << std::endl;
    }
    TerminateThread(threadClient.second, 0);
    delete (std::pair<int, HANDLE>*)cl;
}
