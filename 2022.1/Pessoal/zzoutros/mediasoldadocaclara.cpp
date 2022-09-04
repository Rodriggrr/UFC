#include <iostream>
using namespace std;

int main()
{
    string xuxaIsGay;
    getline(cin, xuxaIsGay);
    
    for(int i = xuxaIsGay.length() - 1; i >= 0; i--)
        cout << xuxaIsGay[i];
        
    cout << endl;
        
}