#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void num_repetidos(vector<int> &repetidos, vector<int> numeros, vector<int> &numSemRep)
{
    bool rept = false;
    for(int i = 0; i < numeros.size(); i++)
    {
        for(int j = i + 1; j < numeros.size(); j++)
        {
            if(rept)
            {
                if(numeros[i] != numeros[i + 1])
                {
                    rept = false;
                }
                continue;
            }
            if(numeros[i] == numeros[j])
            {
                repetidos.push_back(numeros[i]);
                rept = true;
            }
        }
        if(!rept)
            numSemRep.push_back(numeros[i]);
    }
}

void mostrar_repetidos(vector<int> repetidos)
{
    for(int i = 0; i < repetidos.size(); i++)
    {
        cout << repetidos.at(i);
        if(i + 1 != repetidos.size())
            cout << " ";
    }
    cout << endl;
}

int main()
{
    int elVetor;
    cin >> elVetor;
    vector<int> numeros;

    for(int i = 0; i < elVetor; i++)
    {
        int num;
        cin >> num;
        numeros.push_back(num);
    }
    sort(numeros.begin(), numeros.end());

    vector<int> numSemRep;
    vector<int> repetidos;
    
    num_repetidos(repetidos, numeros, numSemRep);
    cout << numSemRep.size() << endl;
    mostrar_repetidos(repetidos);
}