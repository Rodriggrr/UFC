#include <iostream>
using namespace std;

int main()
{
    int jog1, jog2, jog3;
    cin >> jog1;
    cin >> jog2;
    cin >> jog3;
    if(jog1 == jog2 && jog1 == jog3)
        cout << "empate"; 
    else
        (jog1 == jog2) ? cout << "jog3" : 
        (jog2 == jog3) ? cout << "jog1" : cout << "jog2";
    cout << endl;
}