// #include "Snake.h"
#include <iostream>

void Setup();  // настройка параметров при старте игры
void Draw();  // отрисовка карты
void Input();  // отслеживание нажатий пользователя
void Logic();  // логика игры
// void Output();  // итоговый выход
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup() {
  gameOver = false;
  dir = STOP;
  x = width / 2;
  y = height / 2;
  fruitX = std::rand() % width;
  fruitY = std::rand() % height;
  score = 0;
}

void Draw() {
  std::system("clear");
  for (int i = 0; i < width + 1; ++i) {
    std::cout << "#";
  }
  std::cout << std::endl;
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      if ((j == 0) || (j == width - 1)) {
        std::cout << "#";
      }
      std::cout << " ";
    }
    std::cout << std::endl;
  }
  for (int i = 0; i < width + 1; ++i) {
    std::cout << "#";
  }
  std::cout << std::endl;
}

void Input() {}
void Logic() {}

int main() {
  Setup();
  while (!gameOver) {
    Draw();
    Input();
    Logic();
  }
  return 0;
}

// int main() {
//   Output();
//   return 0;
// }