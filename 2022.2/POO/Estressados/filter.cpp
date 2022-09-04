#include <iostream>
#include <vector>
#include "cout.hpp"
using namespace std;

vector<int> get_men(vector<int> x)
{
    vector<int> men;
    for(auto a : x)
        if(a > 0)
            men.push_back(a);
    return men;
}

vector<int> get_calm_women(vector<int> x)
{
    vector<int> women;
    for(auto a : x)
        if(a < 0 && a > -10)
            women.push_back(a);
    return women;
}

int main()
{
    vector <int> x, y;
    x = get_men({1, -3, 5, 6, -7});
    y = get_calm_women({-12,-4, 5, -24, 2, 3, -5});

    cout << x << endl;
    cout << y << endl;
    }