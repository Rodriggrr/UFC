#include <iostream>
#include <vector>
using namespace std;

int rept(vector<int> op)
{
    cout << "[ ";
    for(int i = 0; i < op.size(); i++)
    {
        cout << op[i] << " ";
    }
    cout << "]" << endl;
    return 0;
}

int main()
{
    int pNaFila;
    cin >> pNaFila;
    vector<int> impar, par;
    int vetor[pNaFila];

    for(int i = 0; i < pNaFila; i++)
    {
        cin >> vetor[i];

        if(vetor[i] % 2 == 0)
        {
            par.push_back(vetor[i]);
        }
        else
        {
            impar.push_back(vetor[i]);
        }
    }
    rept(impar);
    rept(par);
}