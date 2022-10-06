#include <iostream>
#include <iomanip>
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
    cliente = socket(AF_INET, SOCK_DGRAM, 0);
    

    struct sockaddr_in servidor;
    servidor.sin_family = AF_INET;
    servidor.sin_addr.s_addr = inet_addr("192.168.137.27");
    servidor.sin_port = htons(8922);

    if(iResult == SOCKET_ERROR){
        std::cout << "conexão mal-sucedida: " << WSAGetLastError() << std::endl;
    }

    //std::cout << "Digite uma mensagem para iniciar a conexão com o servidor: ";

    int serverSize = sizeof(servidor);

    std::cin >> msg;

    sendto(cliente, msg, sizeof(msg), 0, (struct sockaddr *)&servidor, sizeof(servidor)); // Primeiro número;

    std::cin >> msg;
    sendto(cliente, msg, sizeof(msg), 0, (struct sockaddr *)&servidor, sizeof(servidor)); // Segundo número;

    std::cin >> msg;
    sendto(cliente, msg, sizeof(msg), 0, (struct sockaddr *)&servidor, sizeof(servidor)); // Operação.

    while(iResult = recvfrom(cliente, msg, sizeof(msg), 0, (struct sockaddr *)&servidor, &serverSize) == SOCKET_ERROR); // Resultado.
    
    std::string resultado = buffer_string(msg);
    resultado.resize(resultado.find_first_of("0"));

    std::cout << std::fixed << std::setprecision(2) << resultado << std::endl; // mostra o resultado.

    std::cin.ignore(2);
    std::cin.get();

}