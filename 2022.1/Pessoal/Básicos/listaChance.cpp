#include <iostream>
#include <ctime>
#include <vector>
#include <windows.h>
#include <exception>
using namespace std;

void choosing_anim(){
    for(int i = 0; i < 3; i++){
        cout << "\rEscolhendo... /";  Sleep(250);
        cout << "\rEscolhendo... -";  Sleep(250);
        cout << "\rEscolhendo... \\"; Sleep(250);
        cout << "\rEscolhendo... |";  Sleep(250);
    }
}

int main()
{
    srand(time(NULL));
    cout << "DICA: Na primeira linha, você pode escrever quantos ganhadores serão, de 2 a 9.\n";
    cout << "Digite a lista e escreva \"b\" quando terminar.\n---------------------" << endl;

    COORD coord;
    coord.X = 0;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int linha = 4;

    vector<string> lista;
    string nome1;
    getline(cin, nome1);
    int ganhadores = 1;

    if(isdigit(nome1[1])) throw std::runtime_error("Número inadequado.");

    if(isdigit(nome1[0]))
        if((int)nome1[0] - 48 < 2) 
            throw std::runtime_error("Número tem que ser maior do que 1.");
        else
            ganhadores += ((int)nome1[0] - 48) - 1;

    else lista.push_back(nome1);
        

    while(true)
    {
        string nome;
        getline(cin >> ws, nome);

        coord.Y = linha;
        linha++;

        if(nome == "b"){
            SetConsoleCursorPosition(hConsole, coord);
            cout << "---------------------\n";
            break;
        }

        lista.push_back(nome);
    }

    choosing_anim();

    cout << "\r               \r";
    vector<int> repetidos;
    for(int i = 0; i < ganhadores; i++){

        int random = rand() % (lista.size());
        
        for(int j = 0; j < repetidos.size(); j++){
            if(random == repetidos[j]){
                random = rand() % (lista.size());
                j--;
            }
        }

        repetidos.push_back(random);
        cout << lista.at(random) << endl;
    }
}