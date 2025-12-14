#include <iostream>

int getValueFromUser() {
  std::cout << "Enter an integer: ";

  int num{};
  std::cin >> num;

  return num;
}

int main() {
  int num{getValueFromUser()};
  std::cout << "Double that number is: " << num * 2 << '\n';
  return 0;
}
