#include <iostream>
using namespace std;

int min(int a, int b)
{
    if(a < b)
        return a;

    return b;
}

//boolean = 0, 1
bool a_amanda_eh_linda(string amanda)
{
    if(amanda == "linda")
        return true;
    return false;
}

double Div(double a, double b)
{
    if(b == 0)
    {
        cout << "Impossível divisão por zero.\n";
        return 0;
    }
    
    return a / b;
}

int main()
{
    cout << min(2, 3) << '\n';
    string amanda = "linda";
    if(a_amanda_eh_linda(amanda))
        cout << "Meu deus quero te amar\n";

    cout << Div(2, 1) << " " << Div(2, 0);

    
    cout << "Amanda\n";
    cout << "Rodrigo\n";
    cout << "Amanda\n";
    cout << "Rodrigo\n";

    

}