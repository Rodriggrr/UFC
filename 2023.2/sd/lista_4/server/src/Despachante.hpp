#ifndef SERVER
    #include "TCPServer.cpp"
#endif

#include "Esqueleto.hpp"

struct Despachante : Esqueleto {

    static std::string invoke(std::string args) {
        auto operation = fn::split(args, ',')[0];
        auto nums = fn::split(args, ',')[1];

        if      (operation == "ADD") { return Esqueleto::add(nums); }
        else if (operation == "SUB") { return Esqueleto::sub(nums); }
        else if (operation == "MUL") { return Esqueleto::mul(nums); }
        else if (operation == "DIV") { return Esqueleto::div(nums); }

        std::cout << "Invalid Operation" << std::endl;
        return "-1";
    }   
};