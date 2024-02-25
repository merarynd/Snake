#ifndef S21_SNAKE_H_
#define S21_SNAKE_H_
// #include <conio.h>
#include <ncurses.h>

#include <iostream>

// class Snake {
//  public:
void Setup();  // настройка параметров при старте игры
void Draw();  // отрисовка карты
void Input();  // отслеживание нажатий пользователя
void Logic();   // логика игры
void Output();  // итоговый выход
int _kbhit();
int _getch();

//  private:
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
// };

#endif  // S21_SNAKE_H_