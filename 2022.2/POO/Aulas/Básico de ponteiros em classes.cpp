/*
************************************************ BÁSICO DE PONTEIROS *****************************************************

    void* ponteiro;    <<<<< ponteiro do tipo VOID: estritamente guarda o inteiro para um bloco de memória; 
                             impossível de-referenciar.

    *ponteiro;         <<<<< tentativa de de-referenciar. Impossível ja que, por ser do tipo VOID, 
                             não há como saber qual tipo assumir.

    OBS: de-referenciar: Obter o valor armazenado no bloco de memória ao qual o ponteiro está apontando.

    int a = 2;
    int* ponteiro2 = &a; <<< 'ponteiro2' recebe o bloco de memória de 'a'.

    *ponteiro2;          <<< 'ponteiro2' representa o valor armazenado no bloco de memória ao qual está apontando. 
                              No caso, seria 2,  já que 'a' é 2. 
                              Como atribuímos o tipo INT para o ponteiro, ele sabe qual tipo de valor incorporar.

    auto* ponteiroAuto;  <<< Ponteiro universal: consegue de-referenciar qualquer tipo ao que está atribuído, utilizando
                             do tipo AUTO do C++, que "adivinha" o tipo ao qual ele está sendo de-referenicado.

**************************************************************************************************************************

*/


#include <iostream>
#include <vector>
using namespace std;

class test{
    public:
    int value;
    test(int test_num)
    {
        this->value = test_num;
        cout << "construtor do teste num: " << value << endl;
    }
    ~test()
    {
        cout << "teste num " << value << " destruído.\n"     ;
    };
};

int main()
{
    vector<int> vet {1,2,3,4,5,3};
    test teste(1);               // declaração comum de uma variável: memória armazenada no escopo. Criado no escopo, destruído no escopo.
    test* newTest = new test(2); //'new': memória armazenada na memória geral da aplicação, não dentro do escopo. So será destruído com 'delete';
    cout << '\n';

    test* ptr = &teste;
    int* intPtr = &ptr->value;
    

    cout << ptr << " ---< Valor de memória do ponteiro para a varável 'teste'.\n";
    cout << ptr->value << " ---< Valor do 'int value' da classe teste.\n";
    cout << (void*)intPtr << " ---< Valor da memória do ponteiro para o 'int value' da classe 'teste'.\n"; //Conversão para VOID: representa bloco de memória.
    cout << *intPtr << " ---< Valor armazenado na memória do 'int value' da classe 'teste'.\n\n";
    cout << "destrutor do teste " << newTest->value << " sendo chamado através da função delete: ";
    delete(newTest);
    cout << endl;

    cout << "fim do escopo: ";
}