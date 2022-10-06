#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include "window.hpp"
struct Position
{
    int x;
    int y;
};

std::vector<Position> snake;
Position food;

char heading = 'd';
HANDLE threadID;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void keyThread(void)
{
    while (true)
    {
        Sleep(50);
        if (kbhit())
        {
            if (GetAsyncKeyState(VK_UP) && heading != 's')
                heading = 'w';

            else if (GetAsyncKeyState(VK_DOWN) && heading != 'w')
                heading = 's';

            else if (GetAsyncKeyState(VK_LEFT) && heading != 'd')
                heading = 'a';

            else if (GetAsyncKeyState(VK_RIGHT) && heading != 'a')
                heading = 'd';
            else if (GetAsyncKeyState(VK_ESCAPE))
                break;
        }
    }
    TerminateThread((HANDLE)threadID, 0);
}

void menu()
{
    gotoxy(0, 0);
    std::cout << "Snake Game" << std::endl;
    std::cout << "Press any key to start" << std::endl;
    std::cout << "Press ESC to exit" << std::endl;
}

void show_snake()
{
    for (size_t i = 0; i < snake.size(); i++)
    {
        gotoxy(snake[i].x, snake[i].y);
        std::cout << "■";
    }
    gotoxy(0, 0);
    Sleep(150);
    Position snakeEnd = snake[snake.size() - 1];
    gotoxy(snakeEnd.x, snakeEnd.y);
    std::cout << " ";
}


void put_food()
{
    bool valid = false;
    srand(time(NULL));
    while (!valid)
    {
        valid = true;
        food.x = rand() % 78;

        while (food.x % 2 != 0)
            food.x = rand() % 78;

        for (auto a : snake)
            if (a.x == food.x && a.y == food.y)
            {
                valid = false;
                break;
            }
    }

    food.y = rand() % 38;
    gotoxy(food.x, food.y);
    std::cout << "¤";
}

bool check_eaten_food()
{
    if (snake[0].x == food.x && snake[0].y == food.y)
    {
        Position snakeEnd = snake[snake.size() - 1];
        snake.push_back(snakeEnd);
        return true;
    }
    return false;
}

void check_wall_collision()
{
    if (snake[0].x > 78)
        snake[0].x = 0;
    else if (snake[0].x < 0)
        snake[0].x = 78;
    else if (snake[0].y >= 38)
        snake[0].y = 0;
    else if (snake[0].y < 0)
        snake[0].y = 38;
}

void correct_snake()
{
    for (size_t i = snake.size() - 1; i > 0; i--)
    {
        snake[i].x = snake[i - 1].x;
        snake[i].y = snake[i - 1].y;
    }
    check_wall_collision();
}

bool check_self_collision()
{
    for (size_t i = 1; i < snake.size(); i++)
    {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
            return true;
    }
    return false;
}

bool check_wrong_direction()
{
    std::vector<Position> temp = snake;
    correct_snake();
    if (snake[0].x == snake[1].x && snake[0].y == snake[1].y){
        std::cout << "Wrong direction" << std::endl;
        return true;
    }
    return false;

}

void game()
{
    put_food();
    while (true)
    {
        correct_snake();
        switch (heading)
        {
        case 'w':
            snake[0].y--;
            break;

        case 's':
            snake[0].y++;
            break;

        case 'a':
            snake[0].x -= 2;
            break;
        case 'd':
            snake[0].x += 2;
            break;
        }
        
        if(check_self_collision())
            break;

        if(check_eaten_food())
            put_food();
        show_snake();
        

    }
}

void create_snake()
{
    snake.push_back({60, 15});
    snake.push_back({58, 15});
    snake.push_back({56, 15});
    snake.push_back({54, 15});
}

int main()
{
    create_snake();
    threadID = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)keyThread, NULL, 0, NULL);
    menu();
    _getch();
    system("cls");

    game();
    gotoxy(0, 0);
    show_snake();
    std::cout << "Game Over" << std::endl;
}