#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <iostream>

std::string buffer_string(char *buffer)
{
    std::string var{};
    for (int i = 0; i < strlen(buffer); i++)
    {
        var += buffer[i];
    }
    return var;
}

int main()
{
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    struct sockaddr_in sockete, sockcliente;
    sockete.sin_addr.s_addr = inet_addr("192.168.230.62");
    sockcliente.sin_family = SOCK_DGRAM;
    sockete.sin_family = SOCK_DGRAM;
    sockete.sin_addr.s_addr = htonl(INADDR_ANY);
    sockete.sin_port = htons(8922);

    int servidor = socket(2, SOCK_DGRAM, 0);

    bind(servidor, (struct sockaddr *)&sockete, sizeof sockete);
    listen(servidor, 10);

    int cliente, clientetam = sizeof(sockcliente);
    int msgcliente;

    char buffer[1024] = "Entre 2 e 3, qual é o maior número?";

    while (1)
    {

        if (msgcliente = recvfrom(servidor, buffer, sizeof buffer, 0, (struct sockaddr *)&sockcliente, &clientetam) != SOCKET_ERROR)
        {
            puts(buffer);
            char msg[1024] = "Escolha o maior numero de 2 e 3";
            sendto(servidor, msg, sizeof msg, 0, (struct sockaddr *)&sockcliente, clientetam);

            msgcliente = SOCKET_ERROR;

            while (1)
                if (msgcliente = recvfrom(servidor, buffer, sizeof buffer, 0, (struct sockaddr *)&sockcliente, &clientetam) != SOCKET_ERROR)
                    break;

            puts(buffer);

            if (buffer_string(buffer) == "3")
            {
                char bufferauxiliar[1024] = "Acertou mizerave! ";
                sendto(servidor, bufferauxiliar, sizeof bufferauxiliar, 0, (struct sockaddr *)&sockcliente, clientetam);
            }
            else
            {
                char bufferauxiliar[1024] = "Errou mizerave! ";
                sendto(servidor, bufferauxiliar, sizeof bufferauxiliar, 0, (struct sockaddr *)&sockcliente, clientetam);
            }
            puts(buffer);
        }
    }
}
