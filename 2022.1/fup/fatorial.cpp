#include <iostream>
using namespace std;

int main()
{
    long double v1, v2;
    cin >> v1;
    v2 = v1;
    while(v1 != 1)
    {
        v2 = v2 * (v1 - 1);
        v1--;
    }
    cout << v2 << endl;
}