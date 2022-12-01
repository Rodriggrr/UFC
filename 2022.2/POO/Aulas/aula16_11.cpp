#include <iostream>

double divide(int a, int b){
    if(b == 0){
        throw std::string("fail: divisão por zero");
    }
    return (double) a / b;
}

int main()
{
    int a = 5;
    int b = 0;
    try{
        std::cout << divide(a, b) << std::endl;
    } catch (std::string &e){
        std::cout << e;
    }
}