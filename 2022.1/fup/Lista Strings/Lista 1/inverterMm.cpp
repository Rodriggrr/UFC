#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string frase;
    getline(cin, frase);

    for(int i = 0; i < frase.size(); i++)
    {
        if(islower(frase[i]))
            cout << ((char) (frase[i] - 32));
        else if (isupper(frase[i]))
            cout << ((char)(frase[i] + 32));
        else    
            cout << frase[i];
    }
    cout << endl;
}