#include <conio.h>
#include <time.h>

#include <sstream>
#include <string>
#include <vector>

#include "window.h"  //redimensionar a janela para 40 por 20 caracteres.

int points = 0, size = 3;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
#define MOVE(x) SetConsoleCursorPosition(h, x)
void M_MOVE(int x, int y) {
  COORD cd;
  cd.X = x;
  cd.Y = y;
  MOVE(cd);
}

int lose();
int menu();

void clrscrn() {
  M_MOVE(0, 0);
  for (int i = 0; i < 40; i++) {
    for (int j = 0; j < 20; j++) cout << " ";

    cout << endl;
  }
  M_MOVE(0, 0);
}

struct obj {
 public:
  COORD coord;
  void change_coord(int x, int y) {
    coord.X = x;
    coord.Y = y;
  }
};

void show_snake(vector<obj> x) {
  for (int i = 0; i < (int)x.size(); i++) {
    MOVE(x[i].coord);
    cout << "#";
  }
}

char verify_side(vector<obj> x, char choice) {
#define EQUAL x[0].coord.X == x[2].coord.X &&x[0].coord.Y == x[2].coord.Y
  switch (choice) {
    case 'd':
      x[0].coord.X += 2;
      return (EQUAL) ? 'a' : 'd';
      break;
    case 'a':
      x[0].coord.X -= 2;
      return (EQUAL) ? 'd' : 'a';
      break;
    case 'w':
      x[0].coord.Y--;
      return (EQUAL) ? 's' : 'w';
      break;
    case 's':
      x[0].coord.Y++;
      return (EQUAL) ? 'w' : 's';
      break;
    case 'f':
      return 'f';
      break;
    case 'm':
      return 'm';
      break;
    default:
      return 'd';
      break;
  }
}

vector<obj> fix_snake(vector<obj> x) {
  for (int i = x.size() - 1; i > 0; i--) {
    x[i] = x[i - 1];
  }
  return x;
}

bool verify_col(vector<obj> x) {
  for (int i = 1; i < (int)x.size(); i++)
    if (x[0].coord.X == x[i].coord.X && x[0].coord.Y == x[i].coord.Y)
      return true;

  return false;
}

vector<obj> mov_snake(vector<obj> x, char &choice) {
  switch (choice) {
    case 'd':
      x[0].coord.X += 2;
      break;
    case 'w':
      x[0].coord.Y--;
      break;
    case 's':
      x[0].coord.Y++;
      break;
    case 'a':
      x[0].coord.X -= 2;
      break;
  }

  return x;
}

obj delete_last(obj x) {
  MOVE(x.coord);
  cout << " ";
  return x;
}

vector<obj> correct_pos(vector<obj> x) {
  if (x[0].coord.X >= 40) x[0].coord.X = 0;
  if (x[0].coord.X < 0) x[0].coord.X = 39;
  if (x[0].coord.Y >= 20) x[0].coord.Y = 0;
  if (x[0].coord.Y < 0) x[0].coord.Y = 19;
  return x;
}

void put_food(vector<obj> x, obj &y) {
  int randY, randX;
  srand(time(NULL));
  randY = rand() % 17;
  randX = rand() % 37;

  for (int i = 0; i < x.size(); i++)
    if (randX == x[i].coord.X && randY == x[i].coord.Y) {
      randY = rand() % 17;
      randX = rand() % 37;
      i = -1;
    }

  if (randY % 2 != 0) randY--;
  if (randX % 2 != 0) randX--;
  y.change_coord(randX, randY);
  MOVE(y.coord);
  cout << "@";
}

bool verify_eat(vector<obj> snake, obj fruit) {
  if ((snake[0].coord.X == fruit.coord.X &&
       snake[0].coord.Y == fruit.coord.Y) ||
      (snake[1].coord.X == fruit.coord.X &&
       snake[1].coord.Y == fruit.coord.Y)) {
    points++;
    size++;
    return true;
  }
  return false;
}

void change_title() {
  string frase = "Pontos: ";
  frase += to_string(points);
  frase += " | Tamanho: ";
  frase += to_string(size);

  LPCSTR str;
  str = frase.c_str();

  SetConsoleTitleA(str);
}

int snake() {
  vector<obj> snake(3);
  obj lastDot, fruit;

  // declarando as tres posições iniciais da cobra.
  snake[0].change_coord(4, 10);
  snake[1].change_coord(2, 10);
  snake[2].change_coord(0, 10);

  lastDot = snake[2];  // definindo o ultimo ponto, sera apagado depois.
  char choice = 'd';

  put_food(snake, fruit);
  change_title();
  // processo da cobra, divido em etapas.
  while (true) {
    bool food = true;
    Sleep(25);
    if (kbhit()) choice = getch();
    Sleep(50);
    if (kbhit()) choice = getch();
    Sleep(50);
    if (kbhit()) choice = getch();
    Sleep(50);
    if (kbhit()) choice = getch();
    Sleep(25);

    if (verify_eat(snake, fruit))  // verifica se a comida foi comida.
      food = false;

    if (!food)  //----------------------------- procedimentos para fazer caso a
                //comida tenha sido comida;
    {  //----------------------------- basicamente colocar mais um ponto, criar
       //outra comida e mudar a pontuação.
      change_title();
      fix_snake(snake);
      put_food(snake, fruit);
      food = true;
      snake.push_back(lastDot);
    }
    delete_last(
        lastDot);  // deleta o ultimo ponto, para não ser uma cobra infinita.
    choice =
        verify_side(snake, choice);  // verifica se o lado não é o contrário.
    if (choice == 'f') {
      put_food(snake, fruit);
      choice = 'd';
    }
    snake = mov_snake(snake,
                      choice);  // move a cabeça da cobra para o lado desejado.
    if (verify_col(snake) || choice == 'm')  // condição para perder.
      break;
    lastDot =
        snake[snake.size() - 1];  // variavel recebe o ultimo ponto da cobra
                                  // antes de mudar, para ser apagado.
    snake = correct_pos(snake);  // corrige a posição na tela, para reaparecer
                                 // do outro lado, caso necessario.
    snake = fix_snake(snake);  // transfere cada ponto para o seu próximo ponto.
    show_snake(snake);         // mostra a cobra.
    M_MOVE(39, 19);
  }
  lose();  // caso saia do loop, quer dizer que perdeu.
  return 0;
}

int help() {
  clrscrn();
  M_MOVE(18, 4);
  cout << "INFO:";
  M_MOVE(10, 6);
  cout << "'W A S D' Para mover.";
  M_MOVE(4, 8);
  cout << "Aperte 'M' qualquer hora para MENU.";
  M_MOVE(0, 10);
  cout << "Se bugar e não tiver comida, aperte 'F'.";
  M_MOVE(6, 14);
  cout << "Pressione ENTER para retornar.";
  cin.get();
  return 0;
}

int main() {
  menu();
  clrscrn();
  cout << "Fim de Jogo.";
  return 0;
}

int menu() {
  SetConsoleTitleA("Snake Game");
  points = 0;
  size = 3;
  // UI básica. ---------------------------------------
  M_MOVE(0, 0);
  cout << "Pressione ESPAÇO para escolher.";
  M_MOVE(15, 4);
  cout << "SNAKE GAME";
  M_MOVE(11, 10);
  cout << "Jogar       Finalizar";
  M_MOVE(15, 13);
  cout << "Instruções";
  M_MOVE(13, 9);
  cout << "V";
  //--------------------------------------------------

  // Seta acima dos botões, identidade visual.---------
  char choice = 'a', aux;
  while (choice != ' ') {  // apenas sai quando o jogador apertar espaço.
    aux = choice;
    choice = getch();  // variável armazena o lado que o jogador escolheu.
    if (choice == 'a') {
      cout << "\b ";
      M_MOVE(13, 9);
      cout << "V";
    } else if (choice == 'd') {
      cout << "\b  ";
      M_MOVE(27, 9);
      cout << "V";
    } else if (choice == 's') {
      cout << "\b ";
      M_MOVE(20, 12);
      cout << "V";
    }
  }
  //--------------------------------------------------

  if (aux == 'd')  // dependendo da escolha, uma ação é realizada, no caso jogar
                   // ou sair.
    return 0;
  else if (aux == 's') {
    help();
    clrscrn();
    main();
    return 0;
  }
  clrscrn();
  snake();
  return 0;
}

int lose() {
  clrscrn();
  M_MOVE(14, 7);
  cout << "Você perdeu!!";
  M_MOVE(13, 10);
  cout << "Pressione ENTER \n";
  M_MOVE(10, 11);
  cout << "para retornar ao MENU.";
  cin.get();
  clrscrn();
  main();
  return 0;
}
