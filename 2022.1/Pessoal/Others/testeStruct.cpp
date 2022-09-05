#include <iostream>
#include <cmath>
#include <map>
using namespace std;

class dinheiro
{
private:
    float money;

public:
    float getMoney()
    {
        return money;
    }
    void setMoney(float m)
    {
        money = m;
    }
};
class pessoa : public dinheiro
{
public:
    string Nome;
    string CPF;
    int Idade;
    float Altura;
    float Peso;
    float IMC()
    {
        float IMCTot = Peso / pow(Altura, 2);
        return IMCTot;
    }

public:
    string info()
    {
        cout << Nome << " tem " << Idade << " anos.\n"
             << "Tem uma altura de " << Altura << " metros.\n"
             << "Pesa " << Peso << " quilos.\n"
             << "Seu CPF é " << CPF << ".\n"
             << "Tem um IMC de " << IMC() << ".\n"
             << "E possui " << getMoney() << " reais.\n";
    }
};

int main()
{
    pessoa Rodrigo;
    Rodrigo.Nome = "Rodrigo";
    Rodrigo.Idade = 18;
    Rodrigo.CPF = "1234";
    Rodrigo.Altura = 1.73;
    Rodrigo.Peso = 72.5;
    Rodrigo.setMoney(19.99);
    cout << Rodrigo.info() << endl;

    map<string, int> teste;
    teste[Rodrigo.Nome] = 2;
    cout << teste[Rodrigo.Nome] << endl;
}