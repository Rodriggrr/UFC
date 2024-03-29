#ifndef COMMON
    #include "_common.hpp"
#endif

#include <memory>

class Client {
    bool connected{true};
    int socket_fd{};
    sockaddr_in addr{};
    int port{};
    std::string host = "Anônimo";
    char buffer[4096];

public:

    Client() = default;

    bool isConnected(){
        return connected;
    }

    void setConnected(bool connected){
        this->connected = connected;
    }
    
    bool operator==(const Client& c) const {
        return this->socket_fd == c.socket_fd;
    }

    std::string getIpAddress(){
        return inet_ntoa(addr.sin_addr);
    }

    auto getHost(){
        return host;
    }

    int getPort(){
        return port;
    }

    int getSocketFd(){
        return socket_fd;
    }

    char* getBuffer(){
        return buffer;
    }

    std::string getBufStr(){
        return std::string(buffer);
    }

    sockaddr_in* getAddr(){
        return &addr;
    }

    void setSocketFd(auto socket_fd){
        this->socket_fd = socket_fd;
    }

    void setHost(auto host){
        this->host = host;
    }

    void setAddr(auto addr){
        this->addr = addr;
    }

    void setPort(auto port){
        this->port = port;
    }

    int recv(){
        memset(buffer, '\0', 4096);
        int bytes = ::recv(socket_fd, buffer, 4096, 0);
        return bytes;
    }

    int recv(auto buffer, auto size){
        auto bytes = ::recv(socket_fd, buffer, size, 0);
        return bytes;
    }

    void send(std::string data, int destination=-1){
        if(destination == -1) destination = socket_fd;

        auto bytes = ::send(socket_fd, data.c_str(), data.size(), 0);
        if(bytes < 0) {
            std::cout << "Error sending data" << std::endl;
        }
    }

    void close(){
        ::close(socket_fd);
    }
};