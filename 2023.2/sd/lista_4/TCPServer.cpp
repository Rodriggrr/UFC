#define SERVER
#include <iostream>
#include <thread>
#include <vector>

#include "src/tcpsock.hpp"
using namespace skt;

#include "src/fn.hpp"
#include "src/Connection.hpp"


std::vector<Connection> connections;

int main() {
    Socket sock(49110);

    while(true) {
        auto node = sock.accept();
        connections.push_back(Connection(node));
    }
}


