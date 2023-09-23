#include <iostream>
#include "fn.hpp"
using namespace fn;

int main() {

    while(true) {
        std::string line = input();
        auto args = fn::split(line, ' ');
        write('$' + line);

        
        if(args[0] == "multi") { write(number(args[1]) * number(args[2])); }
        else if(args[0] == "end") break;
    }

}