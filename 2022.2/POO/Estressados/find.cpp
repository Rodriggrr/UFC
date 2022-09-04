#include <iostream>
#include <vector>
using namespace std;

bool in(vector<int> x, int value)
{
    for(auto a : x)      
        if(a == value)
            return true;
    return false;
}

int index_of(vector<int> x, int value)
{
    for(int i = 0; i < (int)x.size(); i++)
        if(x[i] == value)
            return i;
    return -1;
}

int find_if(vector<int> x, int value)
{
    for(int i = 0; i < (int)x.size(); i++)
        if(x[i] > 0)
            return i;
    return -1;
}

int min_element(vector<int> x)
{
    if(x.size() == 0)
        return -1;
    int pos = 0;
    for(int i = 0; i < (int)x.size(); i++)
        if(x[i] < x[pos])
            pos = i;
    return pos;
}

int fin_min_if(vector<int> x)
{
    int pos = -1;
    for(int i = 0; i < (int)x.size(); i++)
        if(x[i] > 0 && (x[pos] > x[i] || pos == -1))
            pos = i;
    return pos;
}

int main()
{
    cout << fin_min_if({2, 3, 4, 3, 1, 2, 2});
}