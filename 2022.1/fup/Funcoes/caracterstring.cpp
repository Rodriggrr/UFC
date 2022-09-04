#include <iostream>
using namespace std;


int count_char(string f, char l, int s)
{
    int count=0;
    if(s >= 0)
    {
        count += count_char(f,l, s-1);
    }
    if(f[s] == l)
        return count+1;

    return count;
}

int main()
{
    string frase;
    getline(std::cin, frase);

    char letra;
    cin >> letra;

    int stgSz = frase.length() - 1;
    int tot = count_char(frase, letra, stgSz);

    cout << tot << endl;

}