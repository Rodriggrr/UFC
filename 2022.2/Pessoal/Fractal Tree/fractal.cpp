#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void first_branch()
{
    gotoxy(59, 29);
    int x = 29;
    for(int i = 0; i < 10; i++){
        gotoxy(59, x);
        x--;
        cout << "■" << endl;
    }
}

void remaining()
{
    
}

int main()
{
        //Making a fractal tree
    first_branch();
    cin.get();

}