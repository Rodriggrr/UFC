#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ver_elem_dif(vector<int> numBola, vector<int> &elemRept, int diferentes)
{
    for(int i = 0; i < numBola.size(); i++)
    {
        if(numBola[i] != numBola[i + 1])
            diferentes++;
        else
            elemRept.push_back(numBola[i]);     
    }  
    return diferentes;
}

vector<int> ver_elem_mais_rept(vector<int> elemMaisRept, vector<int> &elemRept)
{
    int posVetor = 0;
    for(int i = 0; i < elemRept.size(); i++)
    {
        if(elemRept[i] == elemRept[i+1]){
            elemMaisRept.at(posVetor)++;
            elemRept.erase(elemRept.begin() + i);
        }
        else
        {
            elemMaisRept.at(posVetor)++;
            elemMaisRept.push_back(0);
            posVetor++;
        }
    }
    return elemMaisRept;
}   

int main()
{
    int tamVet;
    cin >> tamVet;

    vector<int> numBola(tamVet), elemRept, elemMaisRept(1,0);
    
    for(int i = 0; i < tamVet; i++)
        cin >> numBola.at(i);

    sort(numBola.begin(), numBola.end());
    int diferentes = 0;

    diferentes = ver_elem_dif(numBola, elemRept, diferentes);
    cout << endl;
    cout << diferentes << endl;
    elemMaisRept = ver_elem_mais_rept(elemMaisRept, elemRept);

    for(auto elem : elemRept)
        cout << elem << " ";
}
    