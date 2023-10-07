#include "hello.pb.h"
#include <iostream>

int main() {
    hello::helloWorld msg;
    msg.set_hello("Hello World!");
    std::cout << msg.hello() << std::endl;
}