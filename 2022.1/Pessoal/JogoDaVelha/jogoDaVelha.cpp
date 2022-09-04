#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool velha = true;
void mostrar_matriz(char mt[3][3])
{
    COORD c;
    c.X = 0;
    c.Y = 0;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, c);
    velha = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (mt[i][j] != 'X' && mt[i][j] != 'O')
            {
                cout << " •";
                velha = false;
            }
            else
                cout << " " << mt[i][j];
        }
        cout << endl;
    }
}

void choice(char matriz[3][3], int letter)
{
    char playerLetter = (letter == 0) ? 'O' : 'X';
    char choice;
    choice = getch();
    switch (choice)
    {
    case 'a':
        matriz[1][0] = playerLetter;
        break;
    case 'q':
        matriz[0][0] = playerLetter;
        break;
    case 'z':
        matriz[2][0] = playerLetter;
        break;
    case 'x':
        matriz[2][1] = playerLetter;
        break;
    case 's':
        matriz[1][1] = playerLetter;
        break;
    case 'w':
        matriz[0][1] = playerLetter;
        break;
    case 'e':
        matriz[0][2] = playerLetter;
        break;
    case 'd':
        matriz[1][2] = playerLetter;
        break;
    case 'c':
        matriz[2][2] = playerLetter;
    }
}

char verify_win(char mat[3][3])
{
    bool win = true;
    char winner = 'a';
    for (int i = 0; i < 3; i++)
    {
        if (mat[i][1] == mat[i][0] && mat[i][2] == mat[i][0])
            winner = mat[i][i];
        if (mat[1][i] == mat[0][i] && mat[2][i] == mat[0][i])
            winner = mat[i][i];
    }
    if (mat[0][0] == mat[1][1] && mat[2][2] == mat[0][0])
        winner = mat[0][0];

    if (mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0])
        winner = mat[0][2];

    return winner;
}

void limpar_matriz(char matriz[3][3])
{
    for(int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matriz[i][j] = ' ';
}

int main()
{
    while(true){
        char winner;
        char matriz[3][3];
        mostrar_matriz(matriz);
        int xoro = 0;
        while (true)
        {
            xoro++;
            xoro %= 2;
            choice(matriz, xoro);
            mostrar_matriz(matriz);
            winner = verify_win(matriz);

            if (winner == 'O' || winner == 'X')
            {
                cout << "\n\"" << winner << "\" ganhou!" << endl;
                winner = 'a';
                break;
            }
            else if (velha)
            {
                cout << "Deu velha! Ninguém ganhou.\n";
                break;
            }
        }
        if(winner || velha)
        {
            winner = false;
            velha = false;
            char c;
            cout << "\nDeseja jogar novamente? (s/n)";
            c = getch();
            if(c == 'n')
                return 0;
            else {
                limpar_matriz(matriz);
                mostrar_matriz(matriz);
                for(int i = 0; i < 10; i++){
                    for(int j = 0; j < 50; j++)
                        cout << " ";

                cout << '\n';
                }
                
            }

        }
    }
}