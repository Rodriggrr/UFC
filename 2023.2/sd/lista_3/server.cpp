#include "tcpsock.hpp"
#include <iostream>
#include <thread>

int clients = 0;
using namespace skt;

int main()
{
    Socket server(49101, LOCALHOST, false, true, 100);


    while(true) {
        auto node = server.accept();
        std::cout << "Client " << ++clients << " connected." << std::endl;

        std::thread t = std::thread([](Node* node) {
            node->recv();
            node->send("pong");;
        }, node);
        t.detach();
        clients = clients % 100;
    }
}

// int main() {
//     int server = socket(AF_INET, SOCK_STREAM, 0);
//     sockaddr_in addr;
//     addr.sin_family = AF_INET;
//     addr.sin_port = htons(49101);
//     addr.sin_addr.s_addr = INADDR_ANY;
//     bind(server, (sockaddr*)&addr, sizeof(addr));
//     listen(server, 10);

//     while(true) {
//         int node = accept(server, 0, 0);
//             std::cout << "Client " << ++clients << " connected." << std::endl;

//         std::thread t = std::thread([](int node) {
//             char buffer[1024];
//             recv(node, buffer, 1024, 0);
//             send(node, "pong", 4, 0);
//         }, node);
//         t.detach();
//     }
// }