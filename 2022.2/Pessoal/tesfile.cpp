#include <iostream>
#include "math.hpp"
#include <math.h>

auto soma (auto x, auto y)
{
    return x + y;
}

auto op (auto a, auto b, auto fn){
    return fn(a, b);
}

auto op (auto a, auto b)
{
    return op(a, b, [](auto a, auto b) { return a + b; });
}

auto op (auto a)
{
    return a;
}



int main()
{
    auto x = new int;
    *x = 2;
    delete x;
    std::cout << math::sqrt(3.14) << std::endl;
    std::cout << std::sqrt(3.14) << std::endl;
    std::cout << math::factor(3.14) << std::endl;
    std::cout << soma(std::string("Hello "), std::string("World")) << std::endl;
    std::cout << op(2, 3) << std::endl;
    std::cout << op(2, 3, [](auto a, auto b) { return a - b; }) << std::endl;
    std::cout << op(2);
}