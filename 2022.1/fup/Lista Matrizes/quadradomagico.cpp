#include <iostream>
using namespace std;

int main()
{
    int matriz[3][3];

    int somaDiag1 = 0, somaDiag2 = 0;
    int somaCol = 0, somaLinha = 0;
    

    for(int i = 0; i < 3; i++)
        for(int j=0; j<3; j++)
            cin >> matriz[i][j];

    int somaCol1 = matriz[0][0] + matriz[0][1] + matriz[0][2], 
    somaLinha1 = matriz[0][1] + matriz[0][2] + matriz[0][3];
    for(int i = 0, inv = 2; i < 3; i++, inv--){
        somaDiag1 += matriz[i][i];
        somaDiag2 += matriz[i][inv];
        for(int j = 0; j < 3; j++){
            somaCol += matriz[j][i];
            somaLinha += matriz[i][j];

        }
    }
    if(somaLinha1 == somaCol1)
        if(somaDiag1 == somaDiag2)
            if(somaDiag2 == (somaCol / 3))
                if((somaCol / 3) == (somaLinha / 3))
                    cout << "sim";
                else
                    cout << "nao";
            else
                cout << "nao";
        else 
            cout << "nao";
    else 
        cout << "nao";

    cout << endl;
}