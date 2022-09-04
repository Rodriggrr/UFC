#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int tamVetor;
    cin >> tamVetor;
    vector<int> vetor1(tamVetor), vetor2(tamVetor);

    for(int i = 0; i < tamVetor; i++)
        cin >> vetor1[i];

    for(int i = tamVetor - 1, j = 0; i >= 0; i--, j++)
        vetor2[i] = vetor1[j];

    for(auto a : vetor2)
        cout << a << " ";
}