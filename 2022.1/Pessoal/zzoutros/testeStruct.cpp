#include <iostream>
#include <cmath>
#include <map>
using namespace std;   

int main()
{

        class dinheiro{
            public:
            float money;
        };
        class pessoa : public dinheiro{
        public:
        string Nome;
        string CPF;
        int Idade;
        float Altura;
        float Peso;
        float IMC(){    
           float IMCTot = Peso / pow(Altura, 2);
           return IMCTot;
        }
        public:
        string info(){
            cout << Nome << " tem " << Idade << " anos.\n"
                 << "Tem uma altura de " << Altura << " metros.\n"
                 << "Pesa " << Peso << " quilos.\n"
                 << "Seu CPF é " << CPF << ".\n"
                 << "Tem um IMC de " << IMC() << ".\n"
                 << "E possui " << money << " reais.\n";
            }

    };
    
    pessoa Rodrigo;
    Rodrigo.Nome = "Rodrigo";
    Rodrigo.Idade = 18;
    Rodrigo.CPF = "067-167-513-35";
    Rodrigo.Altura = 1.73;
    Rodrigo.Peso = 72.5;
    Rodrigo.money = 19.99;
    cout << Rodrigo.info() << endl;

    map <string, int> teste;
    teste[Rodrigo.Nome] = 2;
    cout << teste[Rodrigo.Nome] << endl;
}