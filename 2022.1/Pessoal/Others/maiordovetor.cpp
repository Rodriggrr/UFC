#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int tamvetor;
    cin >> tamvetor;

    vector<int> vetor(tamvetor);

    for (int i = 0; i < tamvetor; i++)
    {
        cin >> vetor[i];
    }
    cout << *max_element(vetor.begin(), vetor.end());
}