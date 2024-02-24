#ifndef S21_SNAKE_H_
#define S21_SNAKE_H_
#include <iostream>

class Snake {
 public:
  void Setup();  // настройка параметров при старте игры
  void Draw();  // отрисовка карты
  void Input();  // отслеживание нажатий пользователя
  void Logic();   // логика игры
  void Output();  // итоговый выход
 private:
  bool gameOver;
  const int width = 20;
  const int height = 20;
  int x, y, fruitX, fruitY, score;
  enum eDir { STOP = 0, LEFT, RIGHT, UP, DOWN };
  eDir dir;
};

#endif  // S21_SNAKE_H_