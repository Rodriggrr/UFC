#include <iostream>
#include <cstring>
using namespace std;
#define LOG(x) cout << x << endl


int main()
{
//   int a = 4;
//   int& ref = a;
//   ref = 6;
//   LOG(a);


    char* a = new char[7];
    char* ptr = a;
    for(int i = 0; i < 7; i++){
        char u;
        cin >> u;
        *a = u;
        a++;
    }
    a -= 7;
    for(int i = 0; i < 7; i++){
        cout << *a;
        a++;
    }
}