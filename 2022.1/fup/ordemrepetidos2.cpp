#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> encontrar_repetidos(vector<int> numBola, vector<int> repetidos, vector<int> &repUnicos)
{
    bool repetido = false;
    for (int i = 0; i < (int)numBola.size(); i++)
        if (numBola[i] == numBola[i + 1])
        {
            repetidos.push_back(numBola[i]);

            if (!repetido)
            {
                repUnicos.push_back(numBola[i]);
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
    for (int i = 0; i < (int)repetidos.size(); i++)
        if (repetidos[i] == repetidos[i + 1])
            repContagem.at(posVetor)++;
        else
        {
            repContagem.at(posVetor)++;
            posVetor++;
        }
    return repContagem;
}

void mostrar_mais_repetidos(vector<int> repContados, vector<int> repSemRepetir, int maisRepetido)
{
    for (int i = 0; i < (int)repSemRepetir.size(); i++)
        if (repContados.at(i) == maisRepetido)
        {
            cout << repSemRepetir.at(i);
            if (i + 1 != repContados.size())
                cout << " ";
        }
}

void mostrar_elem_dif(vector<int> numBola)
{
    int diferentes = 0;
    for (int i = 0; i < numBola.size(); i++)
    {
        if (numBola[i] != numBola[i + 1])
            diferentes++;
    }
    cout << diferentes << endl;
}

int main()
{
    int tamVetor;
    cin >> tamVetor;
    vector<int> numBola(tamVetor), repetidos, repSemRepetir;
    for (int i = 0; i < tamVetor; i++)
        cin >> numBola.at(i);
    sort(numBola.begin(), numBola.end());
    mostrar_elem_dif(numBola);
    repetidos = encontrar_repetidos(numBola, repetidos, repSemRepetir);
    vector<int> repetidosContagem(repSemRepetir.size());
    repetidosContagem = contar_repetidos(repetidos, repetidosContagem);
    int maisRepetido = *max_element(repetidosContagem.begin(), repetidosContagem.end());
    mostrar_mais_repetidos(repetidosContagem, repSemRepetir, maisRepetido);
}