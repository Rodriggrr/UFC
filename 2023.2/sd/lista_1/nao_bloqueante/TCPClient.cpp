#ifndef COMMON
    #include "../include/_common.hpp"
#endif
#include "../include/socket.hpp"

Socket client(LOCALHOST0, 7896);
bool connected = false;
std::string host = "";

void inputHandler(){
    std::string msg;
    getline(std::cin, msg);
    if (msg.size() == 0) msg = " ";
    client.send(msg);


    while(true){
        while(host == "");
            std::cout << host << ": ";
        getline(std::cin, msg);
        if (msg.size() == 0) msg = " ";

        if(host != "")    
            printr("\033[F" + horaAtual() + host + ": " + msg);
    
        client.send(msg);
    }
}

void outputHandler(){
    while(true){
        int bytes = client.recv();
        if(bytes < 1) break;

        auto args = fn::split(client.getBufStr(), ' ');
        if(args[0] == "!disconnect") break;
        if(args[0] == "!host") {
            lock();
            args.erase(args.begin());
            host = fn::join(args, " ");
            unlock();
            continue;
        }

        printr(client.getBufStr());
    }
    std::cout << "Server disconnected" << std::endl;
    std::exit(0);
}

int main(){
    client.init(true);

    std::thread input(inputHandler);
    std::thread output(outputHandler);

    input.detach();
    output.join();
}
