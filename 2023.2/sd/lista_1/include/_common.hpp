#define COMMON

#include <fn.hpp>
#include <unistd.h>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>

void printr(std::string msg){
    std::cout << '\r' << msg << std::endl;
}

int mutex = 0;

void lock(){
    while(mutex);
    mutex = 1;
}

void unlock(){
    mutex = 0;
}

std::string horaAtual() {
    auto agora = std::chrono::system_clock::now();
    auto tempo = std::chrono::system_clock::to_time_t(agora);
    std::tm tempoLocal = *std::localtime(&tempo);

    std::ostringstream oss;
    oss << "[" << std::put_time(&tempoLocal, "%H:%M") << "]";
    
    return oss.str();
}
