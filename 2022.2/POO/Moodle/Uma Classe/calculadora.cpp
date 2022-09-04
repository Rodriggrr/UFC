/*
1) Fiz o struct "calculadora", para armazenar todas as funções necessárias, e seus devidos erros
e operações. Fiz sozinho.

2) O código, porser muito parecido com o anterior, teve uma certa facilidade. Tive mais problema em
imprimir um float usando a conversão "(float)". Tive que criar duas variáveis de tipo float auxiliares para
contornar o problema.

3) Fiz em exatamente 48 minutos.
*/

#include <iostream>
#include <iomanip>
using namespace std;

struct calculadora{
    int bateria = 0, bateriaMax = 0;
    float display = 0;

    void init();
    void show();
    void charge();
    void sum();
    void div();
};

void calculadora::init()
{
    cin >> bateriaMax;
    cout << "$init " << bateriaMax << endl;
    bateria = 0;
}

void calculadora::show()
{
    cout << "$show\n";
    cout << "display = "
         << fixed << setprecision(2) << display
         << ", battery = " << bateria << endl;
}

void calculadora::charge()
{
    int carga;
    cin >> carga;
    cout << "$charge " << carga << endl;
    bateria += carga;
    if(bateria > bateriaMax)
        bateria = bateriaMax;
}

void calculadora::sum()
{
    int val1, val2;
    cin >> val1 >> val2;
    cout << "$sum " << val1 << " " << val2 << endl;
    if(bateria >= 1){
        display = val1 + val2;
    }
    else
        cout << "fail: bateria insuficiente\n";
    bateria--;
    if(bateria < 0)
        bateria = 0;
}

void calculadora::div()
{
    int val1, val2;
    cin >> val1 >> val2;
    float val1aux = val1, val2aux = val2;
    cout << "$div " << val1 << " " << val2 << endl;
    if(val2 == 0)
        cout << "fail: divisao por zero\n";
    else if(bateria >= 1){
        display = val1aux / val2aux;
    }
    else
        cout << "fail: bateria insuficiente\n";
    bateria--;
    if(bateria < 0)
        bateria = 0;
}

bool choice_check(string choice, calculadora &cal)
{
    if(choice == "init")
        cal.init();
    else if(choice == "show")
        cal.show();
    else if(choice == "charge")
        cal.charge();
    else if(choice== "sum")
        cal.sum();
    else if(choice == "div")
        cal.div();
    else if(choice == "end")
        return true;
    return false;
}

int main()
{
    calculadora cal;
    while(true){
        string choice;
        cin >> choice;
        if(choice_check(choice, cal))
            break;
    }
    cout << "$end\n";
    return 0;
}