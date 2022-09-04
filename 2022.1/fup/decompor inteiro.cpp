#include<iostream>
#include <vector>


using namespace std;

int main()
{
    int inteiro, numDigitos = 0;
    cin >> inteiro;

    int int2 = inteiro;

    while(int2 > 0)
    {
        int2 /= 10;
        numDigitos++;
    }
    int tamNumero = 1, reverso = 10;
    for(int i = 1; i < numDigitos; i++)
        tamNumero *= 10;

    vector<int> numDecomposto;

    for(int i = numDigitos; i > 0; i--)
    {
        numDecomposto.push_back((inteiro / tamNumero) % reverso);
        tamNumero /= 10;
    }
        for(int i = 0; i < numDigitos; i++)
        {
            if(i != 0)
                cout << " ";
            cout << numDecomposto[i];
        }
        cout << endl;
   return 0;
}