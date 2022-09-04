#include <iostream>
using namespace std;

void ponto_atual(char matriz[][100], int k, int l)
{
    int vivos = 0;
    bool vivo = true;
    if(matriz[k][l] == '.') vivo = false;

    for(int i = k - 1; i <= k + 1; i++){
        if(matriz[i][l + 1] == '#') vivos++;
        if(matriz[i][l - 1] == '#') vivos++;
    }
    if(matriz[k - 1][l] == '#') vivos++;
    if(matriz[k + 1][l] == '#') vivos++;
    
    if(vivos == 3 && !vivo)
        cout << "#";
    else if(!vivo)
        cout << ".";

    if(vivos < 2 && vivo)
        cout << ".";
    else if(vivos > 3 && vivo)
        cout << ".";
    else if(vivo)
        cout << "#";
}

void verificar_matriz(char matriz[][100], int tam1, int tam2)
{
    for(int i=0; i<tam1; i++){
        for(int j=0; j<tam2; j++)
            ponto_atual(matriz, i, j);
        
        cout << endl;
    }
}

int main()
{
    int tam1, tam2;
    cin >> tam1 >> tam2;

    char matriz[tam1][100];

    for(int i=0; i<tam1; i++)
     for(int j=0; j<tam2; j++)
        cin >> matriz[i][j];

    verificar_matriz(matriz, tam1, tam2);

    cout << endl;
}