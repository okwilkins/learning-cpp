#include <iostream>

void printHi() { std::cout << "Hi" << '\n'; }

int main() {
  printHi(); // Ok, the function is called, no value returned

  std::cout << printHi(); // Compile error
}
