#include <iostream>
int main(int n1)
{
    (std::cin >> n1) ? n1 % 2 == 0 ? std::cout << -n1 / 2 : n1 != 0 ? std::cout << (n1 + 1) / 2 : std::cout << "0" : std::cout << "Erro.";    
}