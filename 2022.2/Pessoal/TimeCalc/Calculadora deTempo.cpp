#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

void move(int a, int b)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c;
    c.X = a;
    c.Y = b;
    SetConsoleCursorPosition(h, c);
}

struct program
{
    const long long int lightSpeed = 299792458;
    long int speed;
    float distance, time;
    long double result;
    int colocados = 0, tentativas = 0;

    void calc();
};

program test;

int write_to_option(int opt)
{
    switch(opt)
    {
        case 3: 
            cin >> test.speed;
            test.colocados += 3; 
            test.tentativas++;
            break;
        case 2:
            cin >> test.distance;
            test.colocados += 2;
            test.tentativas++;
            break;
        case 1:
            cin >> test.time;
            test.colocados += 1;
            test.tentativas++;
            break;
    }
}

void do_op(int col)
{
    switch(col)
    {
        case 5:
            test.result = test.distance * 1000 / test.speed;
            test.result *= 1000;
            move(20, 13);
            cout << test.result;
            break;
        
    }
}

void put_cursor()
{
    char choice;
    int opt = 3;
    while(true){
        choice = getch();
        switch(choice){
            case 'w':
                opt++;
                if (opt > 3)
                    opt = 1;
                break;
            case 's':
                opt--;
                if(opt < 1)
                    opt = 3;
                break;
            case 'r':
                move(20, 7);
                cout << test.lightSpeed;
                test.speed = test.lightSpeed;
                test.tentativas++;
                test.colocados += 3;
                break;
            case ' ':
                write_to_option(opt);
                if(test.tentativas == 2)
                    do_op(test.colocados);
                break;
            default:
                opt = opt;
                break;
        }

        switch(opt){
            case 1:
                move(20, 13);
                break;
            case 2: 
                move(20, 10);
                break;
            case 3:
                move(20, 7);
                break;
        }
    }
}

int main()
{
    move(40, 0);
    cout << "Calculadora de Tempo ou Distância.";
    move(20, 6);
    cout << "Velocidade: (em m/s)";
    move(20, 9);
    cout << "Distância: (em km)";
    move(20, 12);
    cout << "Tempo: (em ms, milissegundos)";

    put_cursor();
}