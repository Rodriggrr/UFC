#include <iostream>
using namespace std;

char primo(int num) 
{
    for(int i = 2; i < num; i++)
    {
        if(num % i == 0)
            return '0';
    }
    return '1';
}

int main()
{
    int num;
    cin >> num;
    cout << primo(num) << endl;
}