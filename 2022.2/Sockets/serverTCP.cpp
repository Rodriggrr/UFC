#include<stdio.h>
#include<winsock2.h>
#include<windows.h>
#include<ws2tcpip.h>
#include<iostream>

std::string buffer_string(char*buffer){
    std::string var{};
    for(int i =0; i<strlen(buffer); i++){
        var += buffer[i];
    }
    return var;
}

int main(){
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);

    struct sockaddr_in sockete, sockcliente;
    sockete.sin_family = 2;
    sockete.sin_addr.s_addr = htonl(INADDR_ANY);
    sockete.sin_port= htons(8922);

    int servidor = socket(2,1,0);


    bind(servidor, (struct sockaddr*)&sockete, sizeof sockete);
    listen(servidor, 10);

    int cliente, clientetam = sizeof(sockcliente);
    int msgcliente;
    
    char buffer [1024] = "Entre 2 e 3, qual é o maior número?";

    while(1){
        cliente=accept(servidor, (struct sockaddr*)&sockcliente, &clientetam);
        printf("Cliente Conectado. \n");
         send(cliente, buffer, sizeof buffer,0); 
        msgcliente=recv(cliente, buffer, sizeof(buffer),0);
        puts(buffer);
      
        if(buffer_string(buffer) == "3"){
            char bufferauxiliar[1024] =  "ACERTOU EM SAFADO! \n";
            send(cliente, bufferauxiliar, sizeof bufferauxiliar,0);
        }else{
            
            printf("ERROU Y-Y\n");
        }

        send(cliente, buffer, msgcliente,0);

        puts(buffer);

        closesocket(cliente);
        
    }
    
}