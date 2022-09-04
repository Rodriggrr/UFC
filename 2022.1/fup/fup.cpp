#include <iostream>
using namespace std;

int main()
{
   
    int n, maior = 0;

    cin >> n;

    float array[n];
    long double soma = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> array[i];
        soma += array[i];
    }
    for(int i = 0; i < n; i++)
    {
        if(array[i] > maior)
            maior = array[i];
    }

    cout << "maior cu: " << maior << endl;
    
} 