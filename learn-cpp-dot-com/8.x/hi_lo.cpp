#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <random>

namespace Constants {
constexpr int tries = 7;
constexpr int mtSeeds = 10;
} // namespace Constants

void printStartPrompt() {
    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have "
              << Constants::tries << " tries to guess what it is.\n";
}

int getUserGuess(int triesAttempted) {
    std::cout << "Guess #" << triesAttempted << ": ";

    int input{};
    std::cin >> input;

    return input;
}

std::mt19937 seedMT(std::random_device &rd) {
    auto rngDevices = [&rd] {
        std::array<std::seed_seq::result_type, Constants::mtSeeds> arr{};
        std::generate(arr.begin(), arr.end(), std::ref(rd));
        return arr;
    }();

    auto ss = std::seed_seq{rngDevices.begin(), rngDevices.end()};
    return std::mt19937{ss};
}

void gameLoop(std::mt19937 mt) {
    int input{};
    const int rndNum = std::uniform_int_distribution{1, 100}(mt);

    for (int triesAttempted{1}; triesAttempted <= Constants::tries; ++triesAttempted) {
        input = getUserGuess(triesAttempted);

        if (input > rndNum) {
            std::cout << "Your guess is too high.\n";
        } else if (input < rndNum) {
            std::cout << "Your guess is too low.\n";
        } else {
            std::cout << "Correct! You win!\n";
            return;
        }
    }

    std::cout << "Sorry, you lost. The correct number was " << rndNum << ".\n";

    return;
}

int main() {
    auto rd{std::random_device()};
    std::mt19937 mt = seedMT(std::ref(rd));
    char userInputPlayAgain{};

    while (true) {
        printStartPrompt();

        gameLoop(mt);

        while (true) {
            std::cout << "Would you like to play again (y/n)? ";
            std::cin >> userInputPlayAgain;

            if (userInputPlayAgain == 'y') {
                break;
            } else if (userInputPlayAgain == 'n') {
                return 0;
            } else {
                continue;
            }
        }
    }

    return 0;
}
