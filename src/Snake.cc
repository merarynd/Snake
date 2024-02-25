#include "Snake.h"
void Setup() {
  gameOver = false;
  dir = STOP;
  x = width / 2 - 1;
  y = height / 2 - 1;
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
      if (i == y && j == x) {
        std::cout << "0";
      } else if (i == fruitY && j == fruitX) {
        std::cout << "F";
      } else {
        bool print = false;
        for (int k = 0; k < nTail; ++k) {
          if (tailX[k] == j && tailY[k] == i) {
            print = true;
            std::cout << "o";
          }
        }
        if (!print) std::cout << " ";
      }
    }
    std::cout << std::endl;
  }
  for (int i = 0; i < width + 1; ++i) {
    std::cout << "#";
  }
  std::cout << std::endl;
  std::cout << "Score:" << score << std::endl;
}

void Input() {
  // if (_kbhit()) {
    switch (getchar()) {
      case 'a':
        dir = LEFT;
        break;
      case 'd':
        dir = RIGHT;
        break;
      case 'w':
        dir = UP;
        break;
      case 's':
        dir = DOWN;
        break;
      case 'x':
        gameOver = true;
        break;
    // }
  }
}

void Logic() {
  int prevX = tailX[0];
  int prevY = tailY[0];
  int preV2X, prev2Y;
  tailX[0] = x;
  tailY[0] = y;
  for (int i = 1; i < nTail; ++i) {
    preV2X = tailX[i];
    prev2Y = tailY[i];
    tailX[i] = prevX;
    tailY[i] = prevY;
    prevX = preV2X;
    prevY = prev2Y;
  }
  switch (dir) {
    case LEFT:
      --x;
      break;
    case RIGHT:
      ++x;
      break;
    case UP:
      --y;
      break;
    case DOWN:
      ++y;
      break;
    case STOP:
      break;
  }
  //   if (x > width || x < 0 || y > height || y < 0) {
  //     gameOver = true;
  //   }
  if (x >= width - 1)
    x = 0;
  else if (x < 0)
    x = width - 2;
  if (y >= height)
    y = 0;
  else if (y < 0)
    y = height - 1;
  for (int i = 0; i < nTail; ++i) {
    if (tailX[i] == x && tailY[i] == y) {
      gameOver = true;
    }
  }
  if (x == fruitX && y == fruitY) {
    score += 10;
    fruitX = std::rand() % width;
    fruitY = std::rand() % height;
    nTail++;
  }
}

void Output() {
  Setup();
  while (!gameOver) {
    Draw();
    Input();
    Logic();
  }
}

// int _kbhit() {
//   std::cout << "Press any key to stop the loop..." << std::endl;

//   while (!std::cin.fail()) {
//     if (std::cin.peek() != EOF) {
//       break;  // Прерываем цикл, если была нажата клавиша
//     }
//   }

//   std::cout << "Key pressed! Exiting the program." << std::endl;

//   return 0;
// }

// int _getch() {
//   char ch;
//   std::cout << "Press any key to stop the loop..." << std::endl;

//   while (1) {
//     if (std::cin.get(ch)) {
//       break;  // Прерываем цикл, если была нажата клавиша
//     }
//   }

//   std::cout << "Key pressed! Exiting the program." << std::endl;

//   return 0;
// }
// extern void Output();

int main() {
  Output();
  return 0;
}