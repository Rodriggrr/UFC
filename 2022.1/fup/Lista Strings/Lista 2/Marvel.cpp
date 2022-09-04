#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string supHr;
    int homiFerro;
    cin >> homiFerro;
    
    string integrantesFerro[homiFerro];
    int forcaIntegrantes[homiFerro];
    
    int timeHF = 0;
    for(int i = 0; i < homiFerro; i++)
    {
        getline(cin, supHr);
        integrantesFerro[i] = supHr;
        cin >> forcaIntegrantes[i];
        timeHF += forcaIntegrantes[i];
    }
    
    int capAmericah;
    cin >> capAmericah;
    
    vector<string> integrantesCap(capAmericah);
    vector<int> forcaMericah(capAmericah);
    
    int timeCAm = 0;
    for(int i = 0; i< capAmericah; i++)
    {
        getline(cin, integrantesCap[i]);
        cin >> forcaMericah[i];
        timeCAm += forcaMericah[i];
    }
        
   
    if(timeHF == timeCAm)
        cout << "Draw\n";
    else if(timeHF > timeCAm)
        cout << "Team Iron Wins\n";
    else
        cout << "Team Captain Wins\n"; 
    
    
    
}