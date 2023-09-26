#include "src/tcpsock.hpp"
#include <iostream>

using namespace skt;

int main() {
    Socket client(49110, true);
    client.connect();

    client.send("DIV,3,2");
    std::cout << client.recv();
}