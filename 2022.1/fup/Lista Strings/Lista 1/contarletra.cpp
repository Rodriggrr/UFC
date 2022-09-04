#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    string frase;
    getline(cin, frase);

    char letra;
    cin >> letra;

    int cont = 0;
    for(int i = 0; i < frase.length(); i++)
        if(frase[i] == letra || frase[i] == letra - 32)
            cont++;
        
    cout << cont << endl;

}