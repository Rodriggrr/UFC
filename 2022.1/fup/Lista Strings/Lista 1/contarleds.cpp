#include <iostream>

using namespace std;

void print_leds(int leds[10])
{
    string ledLig;
    cin >> ledLig;

    int contLeds = 0;

    for(int i = 0; i < ledLig.size(); i++)
    {
        contLeds += leds[((int)ledLig[i] - 48)];
    }
    cout << contLeds;
}

int main()
{
    int qntTeste;
    cin >> qntTeste;

    int leds[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    for(int i = 0; i < qntTeste; i++)
    {
        print_leds(leds);
        cout << endl;
    }
}   