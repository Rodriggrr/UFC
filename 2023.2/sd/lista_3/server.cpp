#include "tcpsock.hpp"
#include <iostream>
#include <thread>

int clients = 0;
using namespace skt;

int main()
{
    Socket server(49101, LOCALHOST, false, true, 5000);


    while(true) {
        auto node = server.accept();
        std::cout << "Client " << ++clients << " connected." << std::endl;

        std::thread t = std::thread([](Node* node) {
            node->recv();
            node->send("pong");;
        }, node);
        t.detach();
    }
}