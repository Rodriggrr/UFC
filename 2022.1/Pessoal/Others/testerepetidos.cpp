#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

bool seRepete = false;

vector<int> encontrar_repetidos(vector<int> tazos, vector<int> repetidos, vector<int> &repUnicos)
{
    bool repetido = false;
    for(int i = 0; i < (int)tazos.size(); i++)

        if(tazos[i] == tazos[i + 1]){
            repetidos.push_back(tazos[i]); 
            ::seRepete = true;

            if(!repetido){
                repUnicos.push_back(tazos[i]);
                repetido = true;
            }
        }
        else
            repetido = false;
    
    return repetidos;
}

vector<int> contar_repetidos(vector<int> repetidos, vector<int> repContagem)
{
    int posVetor = 0;
    for(int i = 0; i < (int)repetidos.size(); i++)
        if(repetidos[i] == repetidos[i + 1])
            repContagem.at(posVetor)++;
        else{
            repContagem.at(posVetor)++;
            posVetor++;
        }
    return repContagem;
}

void mostrar_mais_repetidos(vector<int> repContados, vector<int> repSemRepetir, int maisRepetido)
{
    cout << "[";
    for(int i = 0; i < (int) repSemRepetir.size(); i++)
        if(repContados.at(i) == maisRepetido)
            cout << " " << repSemRepetir.at(i);
        
    cout << " ]" << endl;
}

int main()
{
    srand(time(NULL));

    int tamVetor = rand() % 100;
    cout << tamVetor << endl;
    
    
    vector<int> tazos(tamVetor), repetidos, repSemRepetir;

    for(int i = 0; i < tamVetor; i++)
    {
        tazos.at(i) = rand() % 13;
    }

    sort(tazos.begin(), tazos.end());

    cout << "[";
    for(auto a : tazos)
        cout << " " << a;

    cout << " ]" << endl;
    repetidos = encontrar_repetidos(tazos, repetidos, repSemRepetir);

    if(seRepete)
    {
    vector<int> repetidosContagem(repSemRepetir.size());
    repetidosContagem = contar_repetidos(repetidos, repetidosContagem);

    int maisRepetido = *max_element(repetidosContagem.begin(), repetidosContagem.end());

    mostrar_mais_repetidos(repetidosContagem, repSemRepetir, maisRepetido);   
    }
    else
    {
        cout << "[";
        for(int a : tazos)
            cout << " " << a;

        cout << " ]" << endl;
    }
}