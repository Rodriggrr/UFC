#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    int prob;
    cin >> prob;
    srand(time(NULL));
    int random = rand() % 101;
    if(random < prob)
        cout << "Rodrigo\n";
    else if(random > prob)
        cout << "Fabiano\n";
}