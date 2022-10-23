#include <iostream>

bool check(int x)
{
    if(x != 0)
        return false && std::cout << "x != 0" << std::endl;
    return true;
}

int main()
{
    int x = 1;
    check(x);
}