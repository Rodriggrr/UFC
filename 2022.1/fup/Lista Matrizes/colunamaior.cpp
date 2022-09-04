#include <iostream>
using namespace std;

int main()
{
    int tamMatriz;
    cin >> tamMatriz;

    int matriz[tamMatriz][tamMatriz];

    for(int i=0; i<tamMatriz; i++)
        for(int j=0; j<tamMatriz; j++)
            cin >> matriz[i][j];

    int maior = 0, coluna;
    for(int i=0; i<tamMatriz; i++){
        int somaLinha = 0;
        for(int j=0; j<tamMatriz; j++)
            somaLinha += matriz[j][i];

        if(somaLinha > maior){
            maior = somaLinha;
            coluna = i;
        }
    }
    cout << coluna + 1 << endl;
}
//0 0 0 0
//0 0 0 0
//0 0 0 0
//0 0 0 0