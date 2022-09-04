#include <windows.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>
#include <map>

#include "cout.hpp"
using namespace std;

vector<int> fila {1, -2, 3, 5, 5, 5, 5, 3, 2, 5, 7};

vector<int> acompanhados(const vector<int>& vet)
{
    auto posFix = [=] (int i) {
        if(i < 0) return 0;
        if(i == vet.size()) return i - 1;
        return i;
    };

    vector<int> pos;
    for(int i = 0; i < (int)vet.size(); i++){
        if(vet[posFix(i-1)] < 0 or vet[posFix(i+1)] < 0) 
            pos.push_back(i);
    }
    return pos;
}

vector<int> sozinhos(const vector<int>& vet)
{
    vector<int> pos;
    int j = 0;
    for(auto i = vet.begin(); i != vet.end(); i++){
        if(*prev(i) > 0 and *next(i) > 0 and *i > 0)
        {
            pos.push_back(j);
        }
        j++;
    }
    return pos;
}

map<int, int> Map(const vector<int>& vet)
{
    map<int, int> m;
    for(auto a : vet){
        if(m.find(abs(a)) != m.end())
            m[abs(a)]++;
        else
            m[abs(a)] = 1;
    }
    return m;
}

map<int, int> times(vector<int> vet)
{
    int teamPos{}, index = 1;
    map<int, int> m;
    for(int i = 0; i < (int)vet.size() - 1; i++)
    {
        if(abs(vet[i+1]) == abs(vet[i])){
            index++;
            m[teamPos] = index;
        } else {
            index = 1;
            teamPos = i + 1;
        }
    }
    return m;
}

int casais(vector<int> vet)
{
    int cas{};
    sort(vet.begin(), vet.end(), [](int a, int b){return abs(a) < abs(b);});
    for(auto i = 0; i < vet.size(); i++)
    {
        if(abs(vet[i]) == abs(vet[i+1])){
            cas++;
            i++;
        }
    }
    return cas;
}

vector<int> remover_todos(vector<int> vet, vector<int> v)
{
    for(int i = 0; i < vet.size(); i++){
        vet[i] -= i;
        v.erase(v.begin() + vet[i]);
    }
    return v;
}

vector<int> dance(vector<int> vet)
{
    for(int i = 0;;)
    {
        if (i == vet.size() - 1)
            break;
        if(abs(vet[i]) == abs(vet[i+1]))
        {
            vet.erase(vet.begin() + i);
            vet.erase(vet.begin() + i);
            i = 0;
        } else
            i++;
    }
    return vet;
}

int sortear(const vector<int>& vet)
{
    srand(time(NULL));
    return abs(vet[rand() % vet.size()-1]);
}

void embaralhar(vector<int>& vet)
{
    srand(time(NULL));
    for(int i = 0; i < vet.size(); i++)
    {
        int j = rand() % vet.size();
        swap(vet[i], vet[j]);
    }
}

int main()
{
    embaralhar(fila);
    cout << fila << "------------------- < fila\n";
    cout << Map(fila) << "-------------------- < fnc map\n";
    cout << sozinhos(fila) << "-------------------- < fnc sozinhos\n";
    cout << acompanhados(fila) << "------------------ < fnc acompanhados\n";
    cout << times(fila) << "------------------- < fnc times\n";
    cout << casais(fila) << "------------------- < fnc casais\n";
    cout << remover_todos({0, 2}, fila) << "----------------- < fnc remover_todos\n";
    cout << dance(fila) << "----------------- < fnc dance\n";
    cout << sortear(fila) << "----------------- < fnc sortear\n";
}

