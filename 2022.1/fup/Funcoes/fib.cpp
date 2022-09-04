#include <iostream>
using namespace std;

int fib(int n, int f1, int f2, int f3)
{
    f3 = f2;
    f2 = f1;
    f1 = f2 + f3;
    
    if(n > 3)
    {
       f1 = fib(n-1, f1, f2, f3);   
    }
    cout << n << endl;
        return f1;
}

int main()
{
    int num;
    cin >> num;

    if(num < 3)
        cout << 1 << endl;
    else
        cout << endl << fib(num, 1, 1 ,1) << endl; 
}