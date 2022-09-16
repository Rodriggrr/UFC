/*
************************************************** BÁSICOS DE PONTEIROS ******************************************************

0- PARA QUE USAR?
    Ponteiros são variáveis que armazenam endereços de memória, por isso, são muito úteis para otimizar o uso de memória.
    Ponteiros são muito utilizados em funções, pois permitem que uma função altere o valor de uma variável que está fora
    de seu escopo, ou seja, que está fora da função.
    Ponteiros são muito utilizados em vetores, pois permitem que um vetor seja passado como parâmetro para uma função.
    Ponteiros são essenciais para a programação em geral, pois permitem que uma variável seja acessada de qualquer lugar.

1- DEFINIÇÃO:
    Ponteiro é uma variável que armazena o endereço de memória de outra variável.

2- REFERÊNCIAS:
    Referência é uma variável que também armazena o endereço de memória de outra variável.
    Exemplo: int &ref = x; // 'ref' é uma referência para 'x'.
    Então, referências são ponteiros que não podem ser alterados. Pode-se pegar o endereço de uma referência, mas não o valor.

3- PARA DECLARAR UM PONTEIRO:
    tipo *nome;

4- PARA ATRIBUIR UM ENDEREÇO DE MEMÓRIA A UM PONTEIRO:
    nome = &variável;

5- PARA ACESSAR O VALOR DE UMA VARIÁVEL ATRAVÉS DE UM PONTEIRO:
    *nome;  <<< O asterisco antes do nome é usado para acessar o valor de uma variável através de um ponteiro. Chama-se
                de "operador de desreferenciação."

******************************************************************************************************************************
*/

#include <iostream>
using namespace std;

int main()
{
    // Ponteiros tem tipos: int, float, double, char, bool, etc. Eles também podem ser ponteiros para ponteiros.
    // Necessário declarar o tipo do ponteiro antes do nome quando se vai utilizar o ponteiro para desreferenciação.

    int x = 10;
    int *p; // Declaração de um ponteiro para inteiros.
    p = &x; // Atribuição do endereço de memória de x ao ponteiro p. O operador '&' é usado para pegar o endereço de memória
            // de uma variável. Referênciação.
    cout << "Valor de x: " << x << endl;
    cout << "Endereço de memória de x: " << &x << endl;
    cout << "Valor de p: " << p << endl;
    cout << "Endereço de memória de p: " << &p << endl; // Perceba que o endereço de memória de p é diferente do endereço
    cout << "Valor de x através de p: " << *p << endl;  // de memória de x.
    cout << "Endereço de memória de x através de p: " << &*p << "\n\n"; /* Perceba que o endereço de memória de x 
                                                                         através de p é o mesmo do endereço de memória de x. */

    //--------------------------------------------------------------------------------------------------------------

    // Agora iremos modificar o valor de x através de p.
    *p = 20; // Modificando o valor de x por desreferenciação.
    cout << "Valor de x: " << x << endl;               // Perceba que o valor de x foi alterado para 20.
    cout << "Valor de x através de p: " << *p << endl; // Perceba que o valor de x através de p também foi alterado para 20.

    // Perceba que o valor de x foi alterado para 20, mesmo que não tenhamos utilizado a variável x.

    //--------------------------------------------------------------------------------------------------------------

    //Ponteiros também podem ser declarados com o tipo VOID.
    void *ptr_void; // Ponteiro para "qualquer tipo de dado".
    ptr_void = &x;  // Atribuindo o endereço de memória de x ao ponteiro ptr_void.
                    // Perceba que não é possível desreferenciar um ponteiro do tipo VOID, 
                    // pois não se sabe o tipo de dado que ele aponta.
                    //
                    // cout << *ptr_void; // Erro: não é possível desreferenciar um ponteiro do tipo VOID.
    cout << "\nValor de ptr_void: " << ptr_void << endl;

    // Portanto, para desreferenciar um ponteiro do tipo VOID, é necessário fazer um cast para o tipo de dado que ele aponta.
    cout << "Valor de ptr_void por cast: " << *(int *)ptr_void << endl; // Desreferenciando o ponteiro ptr_void para inteiros.

    // Para que receba realmente qualquer tipo de dado, é necessário utilizar o tipo AUTO.
    auto ptr_auto = &x; // Ponteiro para qualquer tipo de dado.
    cout << "Valor de ptr_auto por desreferenciação: " << *ptr_auto << endl; // Desreferenciando o ponteiro para inteiros.
    // Perceba que o tipo de dado do ponteiro é definido automaticamente pelo compilador.

    //--------------------------------------------------------------------------------------------------------------

    // Ponteiros também podem ser ponteiros para ponteiros.
    int **ptr_to_ptr; // Ponteiro para ponteiros.
    ptr_to_ptr = &p;  // Atribuindo o endereço de memória de p ao ponteiro ptr_to_ptr.
    cout << "\nValor de ptr_to_ptr: " << ptr_to_ptr << endl;
    cout << "Valor de memória de p: " << &p << endl;
    // Perceba que o valor de ptr_to_ptr é o mesmo do endereço de memória de p.
    // Podemos desreferenciar o ponteiro ptr_to_ptr para acessar o valor de p.
    cout << "Valor de p por desreferenciação: " << **ptr_to_ptr << endl;
    // Perceba que o valor de p é o mesmo do valor de x. Portanto, podemos desreferenciar o 
    // ponteiro ptr_to_ptr para acessar o valor de x.

    //--------------------------------------------------------------------------------------------------------------

    //Ponteiros também podem ser utilizados para alocar memória dinamicamente.
    int *p2 = new int; // Alocando memória para um inteiro. O operador new retorna o endereço de memória alocado.
    *p2 = 30;          // Atribuindo o valor 30 ao inteiro alocado.
    cout << "\nValor de p2: " << p2 << endl;
    cout << "Endereço de memória de p2: " << &p2 << endl;
    cout << "Valor de p2 através de desreferenciação: " << *p2 << endl;
    // Por usar new, é necessário usar delete para liberar a memória alocada, para evitar vazamento de memória.
    delete p2; // Liberando a memória alocada para o inteiro.

    //--------------------------------------------------------------------------------------------------------------


    // Ponteiros também podem ser utilizados para alocar memória para vetores.
    int *p3 = new int[5]; // Alocando memória para um vetor de 5 inteiros.
    for (int i = 0; i < 5; i++)
    {
        p3[i] = i + 1; // Atribuindo valores ao vetor.
    }
    cout << "\nValores do vetor alocado dinamicamente: ";
    for (int i = 0; i < 5; i++)
    {
        cout << p3[i] << " "; // Imprimindo os valores do vetor.
    }
    delete[] p3; // Liberando a memória alocada para o vetor.

    //--------------------------------------------------------------------------------------------------------------

    // Ponteiros também podem ser utilizados para alocar memória para matrizes.
    int **p4 = new int *[3]; // Alocando memória para uma matriz de 3 linhas.
    for (int i = 0; i < 3; i++)
    {
        p4[i] = new int[3]; // Alocando memória para cada linha da matriz.
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            p4[i][j] = i + j; // Atribuindo valores à matriz.
        }
    }

    cout << "\n\nValores da matriz alocada dinamicamente:\n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << p4[i][j] << " "; // Imprimindo os valores da matriz.
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        delete[] p4[i]; // Liberando a memória alocada para cada linha da matriz.
    }
    delete[] p4; // Liberando a memória alocada para a matriz.

    //--------------------------------------------------------------------------------------------------------------

    // O básico sobre ponteiros foi abordado. Existem muitas outras coisas que podem ser feitas com ponteiros, porém
    // isso será abordado em outro momento. Espero ter ajudado.

    return 0;
}