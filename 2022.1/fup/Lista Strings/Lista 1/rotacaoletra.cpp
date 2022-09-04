#include <iostream>
using namespace std;

int main()
{
    char n;
    cin >> n;

    int num;
    cin >> num;

    n += num;

    if((int)n < 97)
        n = 123 + ((int) n - 97);
    else if ((int) n > 123)
        n = 97 + ((int) n - 123);

    cout << n << endl;
}