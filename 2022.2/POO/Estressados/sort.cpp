#include <iostream>
#include <vector>
#include "cout.hpp"
using namespace std;

void sort(vector<int> &x) //bubble sort
{
    int size = (int)x.size();
    for(int i = 0, j = 0; j < size; i++){
        if(i == size){
            j++;
            i = j;
        }

        if(x[i] < x[j]){
            int posAux = x[j];
            x[j] = x[i];
            x[i] = posAux;
        }
    }
}

//3, 4, 3, 5, -2, -4

void sort_stress(vector<int> &x)
{
    int size = (int)x.size(), aux {};
    for(int i = 0, j = 0; j < size; i++){
        if(i == size){
            j++;
            i = j;
        }

        if(x[i] < 0) aux = -x[i];
        else aux = x[i];

        if(aux < x[j]){
            int posAux = x[j];
            x[j] = x[i];
            x[i] = posAux;
        }
    }
}

int main()
{
    vector<int> x {3, -2, -3, 4, 6, 5};
    sort_stress(x);
    cout << x;
    sort(x);
    cout << endl << x;
}