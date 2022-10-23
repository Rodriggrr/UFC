#include <windows.h>
#include <iostream>
#include <sstream>
#include <utility>
#include <windowsx.h>

// Convert a entire string to a number MACRO.
#define STRING_TO_INT(x, y) \
    ss << x;                \
    ss >> y;                \
    ss.clear();             \
    x = ""

HWND *showNumPtr; // Pointer to text displayer
std::string addNum = " ";
float num1{0.0}, num2{0.0}, num3{0.0};

// Do the calculation according to the operation.
void calculate(float x)
{
    num3 = x;
    num1 = num3;
}

// lastOp stops from repeating the result if pressing the same operation.
// first makes the procedures for the first number.
bool lastOp = false, first = true, cec = false;
int IDauxiliar;
bool floatNum = false;
bool noNum = false;

// Função com condicionais, lógica e debugging da calculadora.-----------------------------
int do_op(int ID, HWND hWnd)
{
    if (noNum)
        IDauxiliar = ID;
    if (ID == 36)
    {
        if (first)
            return 0;
        noNum = true;
    }

    if (first or IDauxiliar == 36)
    {
        IDauxiliar = ID;
    }
    if (ID > 31 and ID < 36)
        noNum = false;

    bool opPress = false;

    // Observa se é um número ou um ponto.
    if (((ID > 0 && ID < 11) or ID == 31) and !noNum)
    {

        // Debugging: se tiver sido 'C' ou 'CE', reiniciar o número para retirar o 0.
        if (cec)
        {
            addNum = "";
            cec = false;
        }

        // lastOp recebe false quando é um numero.
        lastOp = false;

        // Colocar os números no string.
        if (ID == 10)
            addNum += "0";
        else if (ID == 31)
        {
            addNum += ".";
            floatNum = true;
        }
        else
            addNum += std::to_string(ID);
    }
    else if (ID == 21 or ID == 22) // Observar se é 'C' ou 'CE'.
    {
        cec = true;
        if (ID == 22) // 'C' Reseta o número na tela.
            addNum = "0";
        else // 'CE' Reseta a calculadora.
        {
            num1 = 0;
            num2 = 0;
            num3 = 0;
            addNum = "0";
            first = true;
            noNum = false;
        }
    }
    else // Se nao for numero ou C, CE: É um operador.
    {
        opPress = true;
        floatNum = false;
    }

    // botar dois zeros no final, estetica
    std::string beauty;
    beauty = addNum;
    addNum += (floatNum) ? "" : ".00";

    // Imprimir todos os números.
    DestroyWindow(*showNumPtr);
    *showNumPtr = CreateWindow("STATIC", addNum.c_str(), WS_VISIBLE | WS_CHILD | SS_RIGHT, 5, 22,
                               270, 15, hWnd, (HMENU)20, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);

    // Retira os dois zeros; debugging
    addNum = beauty;

    // op ID's: '+' - 32; '-' - 33; '*' - 34; '/' - 35; '=' - 36.
    if (opPress and !lastOp)
    {
        // StringStream para converter o número no string para uma variável de tipo de número.
        std::stringstream ss;
        std::cout << addNum + "\n";
        float totalNum;
        lastOp = true;

        // Condição para caso seja o primeiro número.
        if (first)
        {
            STRING_TO_INT(addNum, totalNum);
            num1 = totalNum;
            num3 = num1;
            std::cout << num1 << "into2\n";
            first = false;
        }
        else
            switch (IDauxiliar) // Se não for o primeiro, processa a operação de acordo com o operador.
            {
            case 32:
                STRING_TO_INT(addNum, totalNum); // Já explicado em cima.
                num2 = totalNum;                 // num2 recebe o número atual;
                calculate(num1 + num2);          // operação realizada.
                break;                           // O mesmo ocorre nos demais, exceto no igual, ou '36'.
            case 33:
                STRING_TO_INT(addNum, totalNum);
                num2 = totalNum;
                calculate(num1 - num2);
                break;
            case 34:
                STRING_TO_INT(addNum, totalNum);
                num2 = totalNum;
                calculate(num1 * num2);
                break;
            case 35:
                STRING_TO_INT(addNum, totalNum);
                num2 = totalNum;
                calculate(num1 / num2);
                break;
            case 36:
                STRING_TO_INT(addNum, totalNum);
                num2 = totalNum;
                calculate(num1); // não mudamos os valores, e inicializamos a função por debugging. talvez seja redundante.
                lastOp = false;
                noNum = true; // Impedir que escreva um número ao inves de um operador; debugging.
                break;
            }
        IDauxiliar = ID; // operações com atraso para mostrar apenas quando apertado outro operador.
    }
    std::string showNum = std::to_string(num3);
    showNum.resize(showNum.length() - 4); // fazendo o float ter apenas duas casas decimais por mudar o tamanho da string - método perigoso.
    if (lastOp){
        DestroyWindow(*showNumPtr);
        *showNumPtr = CreateWindow("STATIC", showNum.c_str(), WS_VISIBLE | WS_CHILD | SS_RIGHT, 5, 22,
                                   270, 15, hWnd, (HMENU)20, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL);
    }
    return 0;
}

// Função que interpreta mensagens do tecladdo e passam para a função de operação com os ID's de acordo.
int key_input(int x, HWND hWnd)
{
    std::cout << x << '\n';
    if (x > 48 and x < 59)
        do_op(x - 48, hWnd);
    else
        switch (x)
        {
        case 48:
            do_op(10, hWnd);
            break;
        case 88:
            do_op(34, hWnd);
            break;
        case 187:
            do_op(32, hWnd);
            break;
        case 193:
            do_op(35, hWnd);
            break;
        case 189:
            do_op(33, hWnd);
            break;
        case 190:
            do_op(31, hWnd);
            break;
        case 27:
            do_op(21, hWnd);
            break;
        case 8:
            do_op(22, hWnd);
            break;
        case 13:
            do_op(36, hWnd);
            break;
        }
}
