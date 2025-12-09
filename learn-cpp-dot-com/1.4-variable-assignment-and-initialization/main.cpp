#include <iostream>

int main() {
  [[maybe_unused]] double pi{3.14159}; // Don't complain if pi is unused
  [[maybe_unused]] double g{9.8};      // Don't complain if g is unused

  std::cout << pi << '\n';
  std::cout << g << '\n';
}
