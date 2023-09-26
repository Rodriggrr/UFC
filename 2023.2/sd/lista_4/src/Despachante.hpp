#ifndef SERVER
    #include "TCPServer.cpp"
#endif

#include "Esqueleto.hpp"

struct Despachante : Esqueleto {

    static std::string invoke(std::string args) {
        auto params = getParams(args);
        auto operation = params.first;
        auto nums = params.second;
        
        if      (operation == "ADD") { return Esqueleto::add(nums); }
        else if (operation == "SUB") { return Esqueleto::sub(nums); }
        else if (operation == "MUL") { return Esqueleto::mul(nums); }
        else if (operation == "DIV") { return Esqueleto::div(nums); }
        return "FAIL";
    }   

private:

    static std::pair<std::string, std::string> getParams(std::string args) {
        auto params = fn::split(args, ',');
        return std::make_pair(params[0], (params[1] + ',' + params[2])); 
    }
};