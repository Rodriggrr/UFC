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
    Socket sock(49100);
    std::cerr << "Servidor Rodando na porta " << sock.getPort() << std::endl;

    while(true) {
        auto node = sock.accept();
        std::shared_ptr<Node> ptr(node);
        connections.push_back(Connection(ptr));
    }
}


