#include <iostream>
#include <vector>
#define SNAKE_FIX if(tam > 1) corrigir_snake(snake)

using namespace std;

struct dot{
    int X, Y;
};

void corrigir_snake(vector<dot> &snake)
{
    for(int i=snake.size() - 1; i >= 1; i--)
    {
        snake[i] = snake[i - 1];
    }
}

int main()
{
    int tam;
    char dir;
    cin >> tam >> dir;
    vector<dot> snake(tam);
    for(int i=0; i<tam; i++)
        cin >> snake[i].X >> snake[i].Y;
    
    switch(dir){
        case 'L': 
            SNAKE_FIX;
            snake[0].X--;
            break;
        case 'R':
            SNAKE_FIX;
            snake[0].X++;
            break;
        case 'D':
            SNAKE_FIX;
            snake[0].Y--;
            break;
        case 'U':
            SNAKE_FIX;
            snake[0].Y++;
            break;
    }
    for(auto a : snake){
        cout << a.X << " " << a.Y << endl;
    }
}