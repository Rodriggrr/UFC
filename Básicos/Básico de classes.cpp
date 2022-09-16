/*
*************************************** BÁSICO DE CLASSES OU STRUCTS *********************************************

1- Diferença entre 'STRUCT's e 'CLASS'es:
   Struct: uma CLASSE, porém é inicilizado, inicialmente, com tudo PÚBLICO.
   Class:  CLASSES, o mesmo que structs, porém são inicializadas como PRIVADAS.

2- VISIBILIDADE:
   Público: Acessível para todo o código ABAIXO.
   Private: Acessível apenas para elementos da classe.
   Protected: Acessível apenas para elementos da classe e classes derivadas.

3- CONSTRUTORES:
   Funções que são chamadas quando um objeto é criado. São chamadas automaticamente. 
   Um construtor deve ser criado com o mesmo nome da classe, ou seja, o nome da classe é o nome do construtor.
   Um construtor pode receber parâmetros, assim como uma função normal.

4- DESTRUTORES:
   Funções que são chamadas quando um objeto é destruído. São chamadas automaticamente.
   Um destrutor deve ser criado com o mesmo nome da classe, porém com um '~' antes do nome.
   Um destrutor não pode receber parâmetros, diferente de um construtor.
   Objetos são destruídos quando saem de escopo, quando são destruídos com o comando 'delete' ou quando são 
   destruídos automaticamente.

5- MÉTODOS:
   Funções que pertencem a uma classe. São chamadas de métodos, pois são chamadas através de um objeto.
   Um método pode receber parâmetros, assim como uma função normal.

6- ATRIBUTOS:
   Variáveis que pertencem a uma classe. São chamadas de atributos, pois são chamadas através de um objeto.
   Um atributo pode receber valores, assim como uma variável normal.

8- HERANÇA:
   Herança: processo de herdar atributos e métodos de uma classe base para uma classe derivada.
   Classe derivada: classe que herda os atributos e métodos de uma classe base.
   Classe base: classe que fornece os atributos e métodos para uma classe derivada.
   Exemplo: class Cachorro: public Animal { ... };

******************************************************************************************************************
*/

#include <iostream>
using namespace std;

struct Pessoa // Structs são inicializadas como PÚBLICAS, ou seja, todos os elementos são públicos, sem a necessidade de declarar.
{
   // Atributos
   string nome;
   int idade;
   float altura;

   // Construtor
   Pessoa(string n, int i, float a)
   {
      nome = n;
      idade = i;
      altura = a;
   }

   // Destrutor
   ~Pessoa()
   {
      cout << "Objeto destruído" << endl;
   }

   // Métodos
   void falar(string frase)
   {
      cout << nome << " diz: " << frase << endl;
   }
};

class Carro // Classes são inicializadas como PRIVADAS, ou seja, todos os elementos são privados, sendo necessário declarar.
{
   // Atributos
   protected: // Atributos protegidos podem ser acessados por classes derivadas.
      string marca;
      string modelo;
      int ano;
   public:
      int PSI;

   // Construtor
   public:
      Carro(string m, string mo, int a)
      {
         marca = m;
         modelo = mo;
         ano = a;
      }

   // Destrutor
   ~Carro()
   {
      cout << "Objeto destruído" << endl;
   }

   // Métodos
   public:
      void mostrar_carro(string nome_motorista)
      {
         cout << "Marca: " << marca << "\n" << "Modelo: " << modelo << "\nMotorista: " << nome_motorista << endl;
      }

      int get_ano()
      {
         return ano;
      }
};

class Aviao : public Carro // Herança ou Classe Derivada.
{
   // Construtor
   public:
      Aviao(string m, string mo, int a) : Carro(m, mo, a) // Construtor da classe base
      {
         cout << "Avião criado" << endl;
      }

   // Destrutor
   ~Aviao()
   {
      cout << "Objeto destruído" << endl;
   }

   //Métodos
   public:
      void mostrar_aviao(string nome_piloto)
      {
         cout << "Marca: " << marca << "\n" << "Modelo: " << modelo << "\nPiloto: " << nome_piloto << endl;
      }
};

int main()
{
   // Para acessar os elementos de uma classe, basta colocar o nome do objeto seguido de um ponto e o nome do elemento. 
   // Exemplo: 'objeto.elemento'. O mesmo vale para métodos.

   // Struct:
   cout << "Struct:\n"; 
   Pessoa p1("João", 20, 1.80);  // ------ Inicializando um objeto da classe Pessoa.
   p1.falar("Olá, tudo bem?\n"); // ------ Chamando um método da classe Pessoa.

   // Classe:
   cout << "Classe:\n";
   Carro c1("Fiat", "Uno", 2010); // ----- Inicialiando um objeto da classe Carro.
   c1.mostrar_carro("Rodrigo"); // ------- Chamando um método da classe Carro.
   c1.PSI = 32; // ----------------------- Acessando e modificando um atributo público da classe Carro.
   cout << "PSI: " << c1.PSI << "\n\n"; // Acessando e mostrando um atributo público da classe Carro.

   // Herança:
   cout << "Herança:\n";
   Aviao a1("Boeing", "747", 2015); // --- Inicializando um objeto da classe Aviao.
   a1.mostrar_aviao("João\n"); // -------- Chamando um método da classe Aviao.
   cout << "Chamando um método da classe Carro através da classe Aviao:\n";
   a1.mostrar_carro("Rodrigo"); // ------- Chamando um método da classe Carro através da classe Aviao.
   cout << " ^^^^^^^ Repare no \"Motorista\".\n\n";

   // Acessando elementos privados de uma classe através de métodos públicos:
   cout << "Acessando elementos privados de uma classe através de métodos públicos:\n";
   cout << c1.get_ano() << " - ";  // --- Chamando um método público da classe Carro para acessar um atributo privado da mesma.
   cout << a1.get_ano() << "\n\n"; /* --- Chamando um método público herdado da classe Carro para
                                          acessar um atributo privado da classe Aviao. */

   return 0;
}