#include <iostream>
#include <vector>
using namespace std;

void trocar_fig(vector<int> cartas)
{
    vector<int> figRepetida;
    bool semFigRepetida = true;
    for(int i = 0; i < cartas.size(); i++)
    {
        for (int j = i + 1; j < cartas.size(); j++)
        {
            if(cartas[i] == cartas[j])
            {
                figRepetida.push_back(cartas.at(i));
                semFigRepetida = false;
                break;
            }
        }
    }
    for(int i = 0; i < figRepetida.size(); i++)
    {
        cout << figRepetida[i];
        if (i + 1 != figRepetida.size())
        {
            cout << " ";
        }
    }
    if(semFigRepetida)
        cout << "N";
    cout << endl;
}

void fig_restantes(vector<int> cartas, int album)
{
    vector<int> faltaFig;
    bool todos = false, teveFalta = false;
    for (int i = 1; i <= album; i++)
    {
        todos = false;
        for(int j = 0; j < cartas.size(); j++)
        {
            if(i == cartas.at(j))
                todos = true;
        }
        if(!todos)
        {
            faltaFig.push_back(i);
            teveFalta = true;
        }
    }
    for(int i = 0; i < faltaFig.size(); i++)
    {
        cout << faltaFig[i];
        if(i + 1 != faltaFig.size())
            cout << " ";
    }
    if(!teveFalta)
        cout << "N";
    cout << endl;
}

int main()
{
    int numCartaAlbum, numCartaBaruel;
    vector<int> cartas;
    cin >> numCartaAlbum >> numCartaBaruel;

    for(int i = 0; i < numCartaBaruel; i++)
    {
        int num;
        cin >> num;
        cartas.push_back(num);
    }
    trocar_fig(cartas);
    fig_restantes(cartas, numCartaAlbum);
}