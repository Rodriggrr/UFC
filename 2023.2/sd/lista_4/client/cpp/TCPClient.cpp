#include "../server/src/fn.hpp"

#include "Proxy.hpp"
#include <iostream>

using namespace skt;
 
int main() {
    Proxy calc(49100);

    try {
        std::cout << calc.add(1, 7) << std::endl;
        std::cout << calc.sub(9, 6) << std::endl;
        std::cout << calc.mul(8, 4) << std::endl;
        std::cout << calc.div(8, 2) << std::endl;
        calc.close();
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}