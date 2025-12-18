#include "io.h"
#include <iostream>

int readNumber() {
  std::cout << "Type your number: ";

  int input{};
  std::cin >> input;

  return input;
}

void writeAnswer(int num1, int num2) {
  int answer{num1 + num2};
  std::cout << "Your answer is: " << answer;
}
