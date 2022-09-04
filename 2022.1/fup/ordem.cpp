#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int tamVetor;
    cin >> tamVetor;
    vector<int> idade;
    for(int i = 0; i < tamVetor; i++)
    {
        int num;
        cin >> num;
        idade.push_back(num);
    }
    sort(idade.begin(), idade.end());
    for(int i = 0; i < idade.size(); i++)
    {
        cout << idade[i];
        if(i + 1 != idade.size())
            cout << " ";
    }
    cout << endl;
}