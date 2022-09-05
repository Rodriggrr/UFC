#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int tamArray;
    cin >> tamArray;
    int array[2][tamArray];
    int tamanho = sizeof(array) / sizeof(int);
    for(int i=0; i<tamArray; i++)
    {
        cin >> array[0][i];
    }
    for(int i=0; i<tamArray; i++)
    {
        cin >> array[1][i];
    }
    for(int i=0; i < 2; i++)
    {
        for(int j=0; j<tamArray; j++)
        {
            cout << array[i][j]<< endl;
        }
    }
    
    
}