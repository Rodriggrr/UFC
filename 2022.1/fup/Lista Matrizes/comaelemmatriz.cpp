#include <iostream>
using namespace std;

int main()
{
    int matriz[3][2];

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 2; j++)
            cin >> matriz[i][j];

    int soma = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 2; j++)
            soma += matriz[i][j];

    cout << soma << endl;
}       