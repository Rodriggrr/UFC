#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>

std::string buffer_string(char*buffer){
    std::string var{};
    for(int i =0; i<strlen(buffer); i++){
        var += buffer[i];
    }
    return var;
}

int main()
{
    WSADATA wsadata;
    int iResult;
    iResult = WSAStartup(MAKEWORD(2,2), &wsadata);
    if (iResult != 0) {
        std::cout << "WSAStartup failed: " << iResult << std::endl;
        return 1;
    }


    int cliente;
    char msg[1024];
    cliente = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    

    struct sockaddr_in servidor;
    servidor.sin_family = AF_INET;
    servidor.sin_addr.s_addr = inet_addr("192.168.137.27");
    servidor.sin_port = htons(8922);


    iResult = connect(cliente, (struct sockaddr *)&servidor, sizeof(servidor));

    if(iResult == SOCKET_ERROR){
        std::cout << "conexão mal-sucedida: " << WSAGetLastError() << std::endl;
    }

    std::cin >> msg;
    send(cliente, msg, sizeof(msg), 0);

    std::cin >> msg;
    send(cliente, msg, sizeof(msg), 0);

    std::cin >> msg;
    send(cliente, msg, sizeof(msg), 0);
    recv(cliente, msg, sizeof(msg), 0);

    std::string resultado = buffer_string(msg);
    resultado.resize(resultado.length() -5);

    std::cout << resultado << std::endl;
    std::cin.ignore(1);
    std::cin.get();
    closesocket(cliente);

}