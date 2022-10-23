#include "windowResize.hpp" //windows.h included; resive window
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

struct coord
{
    int y = 25;
    int x = 119;
};

class cactus
{
    public:
        vector<coord> v;
        
        void resize_vet()
        {
            coord auxiliar;
            for(int i= 0; i < 18; i++)
                v.push_back(auxiliar);
        }

        void initialize_cactus();
};

void cactus::initialize_cactus()
{
    v[0].y = 23;  v[0].x = 120; 
    v[1].y = 22;  v[1].x = 120;
    v[2].y = 21;  v[2].x = 120;
    v[3].y = 23;  v[3].x = 121;
    v[4].y = 24;  v[4].x = 123;
    v[5].y = 23;  v[5].x = 123;
    v[6].y = 22;  v[6].x = 123;
    v[7].y = 21;  v[7].x = 123;
    v[8].y = 20;  v[8].x = 123;
    v[9].y = 24;  v[9].x = 124;
    v[10].y = 23;  v[10].x = 124;
    v[11].y = 22;  v[11].x = 124;
    v[12].y = 21;  v[12].x = 124;
    v[13].y = 20;  v[13].x = 124;
    v[14].y = 22;  v[14].x = 126;
    v[15].y = 22;  v[15].x = 127;
    v[16].y = 21;  v[16].x = 127;
    v[17].y = 20;  v[17].x = 127;
}

//Move the cursor to a desired place;
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(h, c);
}

//    ##  @
// @  ##  #
// #  ## ##     
// ## ##  
//    ##

//Create the floor of the game;
void create_floor()
{
    //Loop for putting the floor in all 119 characters of the window;
    for(int i = 118;i >= 0; i--)
    {
        gotoxy(i, 25);
        cout << '=';
    }
}

void put_cactus(cactus cacto)
{
    cacto.resize_vet();
    cacto.initialize_cactus();
    int i = 0;
    i = 0;
    for(;;)
    {
        Sleep(5);
        i++;
        gotoxy(15, 0);  cout << i;
        if(i % 3 == 0){
            for(auto a : cacto.v)
            {
                if(a.x >= 0 && a.x < 118){
                    gotoxy(a.x, a.y);
                    cout << " ";
                }
            }
            for(int i = 0; i < 18; i++)
                cacto.v[i].x--;
            for(auto a : cacto.v)
        {
            if(a.x >= 0 && a.x < 118){
                gotoxy(a.x, a.y);
                cout << "#";
            }
        }
        if(cacto.v[17].x == -1)
            break;
        }
    }
}

int main()
{
    Sleep(100);
    cactus cacto;
    create_floor();
    put_cactus(cacto);
    cin.get();
    
}