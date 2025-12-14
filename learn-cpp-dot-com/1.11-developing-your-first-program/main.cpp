#include <iostream>

// Bad solution
int mainBad() {
  std::cout << "Enter an integer: ";

  int num{};
  std::cin >> num;

  num *= 2;

  std::cout << "Double that number is: " << num << '\n';

  return 0;
}

int main() {
  std::cout << "Enter an integer: ";

  int num{};
  std::cin >> num;

  std::cout << "Double that number is: " << num * 2 << '\n';

  return 0;
}
