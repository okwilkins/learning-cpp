#include <iomanip>
#include <iostream>

double getUserDoubleInput() {
    std::cout << "Enter a double value: ";

    double input{};
    std::cin >> input;

    return input;
}

char getUserSymbol() {
    std::cout << "Enter +, -, *, or /: ";

    char input{};
    std::cin >> input;

    return input;
}

int main() {
    double input1{getUserDoubleInput()};
    double input2{getUserDoubleInput()};
    char symbol{getUserSymbol()};

    std::cout << std::setprecision(16);

    if (symbol == '+') {
        std::cout << input1 << ' ' << symbol << ' ' << input2 << " is " << input1 + input2 << '\n';
    } else if (symbol == '-') {
        std::cout << input1 << ' ' << symbol << ' ' << input2 << " is " << input1 - input2 << '\n';
    } else if (symbol == '*') {
        std::cout << input1 << ' ' << symbol << ' ' << input2 << " is " << input1 * input2 << '\n';
    } else if (symbol == '/') {
        std::cout << input1 << ' ' << symbol << ' ' << input2 << " is " << input1 / input2 << '\n';
    } else {
        return 1;
    }

    return 0;
}
