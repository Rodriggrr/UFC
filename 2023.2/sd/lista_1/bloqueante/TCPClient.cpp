#ifndef COMMON
    #include "../include/_common.hpp"
#endif
#include "../include/socket.hpp"

Socket client(LOCALHOST0, 7896);

int main(){
    client.init(true);
    while (true) {
        
        std::string msg;
        getline(std::cin, msg);
        client.send(msg);

        client.recv();
        printf("Server: %s\n", client.getBuffer());
    }


}
