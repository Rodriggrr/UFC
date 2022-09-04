#include <iostream>
#include <vector>
#include "cout.hpp"
using namespace std;


vector<int> unicos(vector<int> x)
{
    vector<int> y;
    for(int i = 0; i < (int)x.size(); i++){
        bool repeat = false;
        for(int j = i + 1; j < (int)x.size(); j++){
            if(x[i] == x[j])
                repeat = true;
        }
        if(!repeat)
            y.push_back(x[i]);
    }
    return y;
}

vector<int> repetidos(vector<int> x)
{
    vector<int> y;
    for(int i = 0; i < (int)x.size(); i++){
        bool repeat = false;
        for(int j = 0; j < (int)x.size(); j++){
            if(x[i] == x[j] && j != i)
                repeat = true;
        }
        if(repeat)
            y.push_back(x[i]);
    }
    return y;
}

int main()
{
    vector<int> x {1, 2, 4, 4, 6, 3, 2, 4, 7}, y, z;
    y = repetidos(x);
    z = unicos(x);

    cout << x << endl << y << endl << z << endl;
}