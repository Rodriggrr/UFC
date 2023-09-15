#include <iostream>
#include "../include/socket.hpp"

class Connection;
Socket server;

int main(){
    server.init();
    auto client = server.accept();
    std::cout << "Client connected: " << client.getIpAddress() << ":" << client.getPort() << std::endl;

    while (true) {

        int client_fd = client.getSocketFd();
        server.recv(client_fd);
        printf("Client: %s\n", server.getBuffer());
        
        std::string msg;
        getline(std::cin, msg);
        server.send(msg, client_fd);

    }

}