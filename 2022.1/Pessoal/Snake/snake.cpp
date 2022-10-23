#include <conio.h>
#include <stdio.h>
#include <windows.h>

#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

#define NUM rand() % 20
#define CON_CG \
  COORD cord;  \
  HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE)
#define POS(a, b) \
  cord.X = a;     \
  cord.Y = b;     \
  SetConsoleCursorPosition(h, cord);

using namespace std;

struct dot {
  int x, y;
};

int pontos = 1;
bool fruit = false, perder = false, nRecord = false;
char choice;
char matrix[20][20];
string recordauxiliar, recordauxiliar2;
int record;

void verificar_recorde() {
  if (record < pontos) {
    ofstream file_out;
    file_out.open("recorde.txt", ios::out);
    file_out << pontos;
    file_out.close();
    nRecord = true;
  }
}

void mostrar_matriz() {
  COORD c;
  c.X = 0;
  c.Y = 0;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(hConsole, c);
  cout << "_________________________________________\n";
  for (int i = 0; i < 20; i++) {
    for (int j = -1; j < 21; j++) {
      if (j == 20 || j == -1) {
        cout << "|";
        continue;
      } else if (matrix[i][j] == '#' || matrix[i][j] == '@') {
        if (matrix[i][j] == '#')
          SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        else
          SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

        cout << matrix[i][j];
        SetConsoleTextAttribute(
            hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
      } else
        cout << " ";
      if (j < 19) cout << " ";
    }

    cout << endl;
  }
  cout << "-----------------------------------------\nTamanho: " << pontos
       << endl
       << "Recorde: " << record << endl;
}

void corrigir_snake(vector<dot> &snake) {
  for (int i = snake.size() - 1; i >= 1; i--) {
    snake[i] = snake[i - 1];
  }
}

void verificar_fruta() {
  bool fruta = false;
  for (int i = 0; i < 20; i++)
    for (int j = 0; j < 20; j++)
      if (matrix[i][j] == '@') fruta = true;

  if (!fruta) fruit = false;
}

void colocar_fruta() {
  while (true) {
    dot ft;
    ft.x = NUM;
    ft.y = NUM;

    if (matrix[ft.y][ft.x] != '+') {
      matrix[ft.y][ft.x] = '@';
      fruit = true;
      break;
    }
  }
}

int lose();

vector<dot> colocar_matriz(vector<dot> s) {
  Sleep(25);
  if (kbhit()) choice = getch();
  dot lastPos;
  for (int i = s.size() - 1; i >= 0; i--) matrix[s[i].y][s[i].x] = '#';

  lastPos = s[s.size() - 1];
  mostrar_matriz();
  switch (choice) {
    case 's':
      if (s[0].y + 1 == s[2].y && s[0].x == s[2].x){
        choice = 'w'; break;
      }
      else if (matrix[s[0].y + 1][s[0].x] == '#') lose();
      s[0].y++;
      break;
    case 'w':
      if (s[0].y - 1 == s[2].y && s[0].x == s[2].x){
        choice = 's'; break;
      }
      if (matrix[s[0].y - 1][s[0].x] == '#') lose();
      s[0].y--;
      break;
    case 'a':
      if (s[0].y == s[2].y && s[0].x - 1 == s[2].x){
        choice = 'd'; break;
      }
      if (matrix[s[0].y][s[0].x - 1] == '#') lose();
      s[0].x--;
      break;
    case 'd':
      if (s[0].y == s[2].y && s[0].x + 1 == s[2].x){
        choice = 'a'; break;
      }
      if (matrix[s[0].y][s[0].x + 1] == '#') lose();
      s[0].x++;
      break;
    case 'l':
      lose();
      break;
    default:
      s[0].x++;
      break;
  }
  s[0].x = (s[0].x > 19) ? 0 : s[0].x;
  s[0].x = (s[0].x < 0) ? 19 : s[0].x;
  s[0].y = (s[0].y > 19) ? 0 : s[0].y;
  s[0].y = (s[0].y < 0) ? 19 : s[0].y;
  if (matrix[s[0].y][s[0].x] == '@') {
    pontos++;
    fruit = false;
    s.push_back(s[s.size() - 1]);
  }

  corrigir_snake(s);
  matrix[lastPos.y][lastPos.x] = '.';

  if (kbhit()) choice = getch();
  if (!fruit) colocar_fruta();

  verificar_fruta();
  return s;
}

int main() {
  ifstream file_in;
  file_in.open("recorde.txt", ios::in);
  file_in >> record;
  file_in.close();

  srand(time(NULL));
  vector<dot> snake;

  dot pos;
  snake.push_back(pos);
  snake[0].x = NUM;
  snake[0].y = NUM;
  snake.push_back(snake[0]);

  while (true) {
    if (kbhit()) choice = getch();
    Sleep(25);
    snake = colocar_matriz(snake);
    if (perder) return 0;
  }
}

int lose() {
  verificar_recorde();
  mostrar_matriz();
  CON_CG;
  if (nRecord) {
    POS(60, 11);
    cout << "  Novo Recorde!, Parabéns!";
    nRecord = false;
    verificar_recorde();
  } else {
    POS(60, 11);
    cout << "       Você Perdeu!!";
  }
  POS(60, 12);
  cout << "Deseja Jogar Novamente?(s/n)";
  POS(60, 13);
  int esc;
  esc = getch();
  if (esc == 's') {
    choice = ' ';
    pontos = 1;
    POS(60, 11);
    cout << "                                ";
    POS(60, 12);
    cout << "                                  ";
    POS(0, 22);
    cout << "                                      ";
    for (int i = 0; i < 20; i++)
      for (int j = 0; j < 20; j++) matrix[i][j] = ' ';
    main();
    return 0;
  } else {
    POS(0, 24);
    cout << "Fim de Jogo.\n";
    perder = true;
  }
}