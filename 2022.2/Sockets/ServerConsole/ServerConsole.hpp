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

bool chatRequest{false};

int consoleCode{};

// Convert the buffer to a string.
std::string buffer_string(char *buffer)
{
    std::string var{};
    for (int i = 0; i < strlen(buffer); i++)
    {
        var += buffer[i];
    }
    return var;
}

char *to_char(char *buffer, std::string var)
{
    for (int i = 0; i < strlen(buffer); i++)
    {
        buffer[i] = var[i];
    }
    return buffer;
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
int *serverTime_ptr;

// Server time routine.
void server_time(int *Time)
{
    int minute, hour, second;
    int serverTime = time(NULL) - *Time;
    hour = serverTime / 3600;
    serverTime = serverTime % 3600;
    minute = serverTime / 60;
    second = serverTime % 60;
    std::cout << "Server time: "
              << std::setw(2) << std::setfill('0') << hour << ":"
              << std::setw(2) << std::setfill('0') << minute << ":"
              << std::setw(2) << std::setfill('0') << second << std::endl;
    std::cout << "> ";
}

// Help routine.
void helpCmd()
{
    std::cout << "clientip - show client ip" << std::endl;
    std::cout << "restart  - restart server" << std::endl;
    std::cout << "clear    - clear console" << std::endl;
    std::cout << "exit     - close server and exit program" << std::endl;
    std::cout << "help     - show this message" << std::endl;
    std::cout << "time     - show server time" << std::endl;
    std::cout << "> ";
}

// Clear routine.
void clearCmd()
{
    system("cls");
    fflush(stdout);
    std::cout << "> ";
}

// Restart routine.
void restartCmd(void *server)
{
    clearCmd();
    consoleCode = 1;
    closesocket((SOCKET)server);
    WSACleanup();
}

// Exit routine.
void exitCmd(void *server)
{
    closesocket((SOCKET)server);
    WSACleanup();
}

// Client ip routine.
void clientipCmd()
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

// The main function for the thread, it will write the data to the console and perform the necessary operations.
int thread_HANDLE;
int threadProc(void *server)
{
    while (true)
    {
        std::string consoleInput;
        std::cout << "";
        std::getline(std::cin, consoleInput);
        if (consoleInput == "exit")
            exitCmd(server);

        else if (consoleInput == "restart")
            restartCmd(server);

        else if (consoleInput == "clear")
            clearCmd();

        else if (consoleInput == "help")
            helpCmd();

        else if (consoleInput == "clientip")
            clientipCmd();

        else if (consoleInput == "time")
            server_time(serverTime_ptr);

        else if (consoleInput == "chat")
        {
                std::cout << "Chat mode enabled." << std::endl;
                consoleCode = 3;
                chatRequest = true;
                char buffer[1024];

                while (consoleInput != "stop")
                {
                    to_char(buffer, "Server: " + consoleInput);
                    send((SOCKET)server, buffer, sizeof (buffer), 0);
                    std::cout << "> ";
                    flushBuffer(buffer);
                    std::cin >> consoleInput;
                }
                chatRequest = false;
                
        }

        else
            std::cout << "Unknown command. Type \"help\" for a list of commands.\n> ";
    }
}
