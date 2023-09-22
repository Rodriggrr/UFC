#include "tcpsock.hpp"
#include <iostream>
#include <thread>

int clients = 0;

int main(){
    skt::Socket server(49100, LOCALHOST, false, true, 10);
    while(true){
        auto node = server.accept();
        std::cout << "Client " << ++clients << " connected." << std::endl;
        std::thread t = std::thread([](skt::Node* node){
            node->recv();
            node->send("pong");
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }, node);
        t.join();
    }


}