#include <iostream>
#include <algorithm>
#include <vector>
#include "cout.hpp"
using namespace std;

bool exists(std::vector<int> vet, int value)
{
    if(find(vet.begin(), vet.end(), value) != vet.end())
        return true;
    return false;
}

std::vector<int> unique(std::vector<int> x)
{
    std::vector<int> unicos, repetidos;
    for (auto i = 0; i < x.size(); i++)
        if (!exists(unicos, x[i]))
            unicos.push_back(x[i]);
        else
            repetidos.push_back(x[i]);
    return unicos;
}

std::vector<int> repeated(std::vector<int> x)
{
    std::vector<int> unicos, repetidos;
    for (auto i = 0; i < x.size(); i++)
        if (!exists(unicos, x[i]))
            unicos.push_back(x[i]);
        else
            repetidos.push_back(x[i]);
    return repetidos;
}

int main()
{
    vector<int> x {1, 2, 4, 4, 6, 3, 2, 4, 7}, y, z;
    y = repeated(x);
    z = unique(x);

    cout << x << endl << y << endl << z << endl;
}