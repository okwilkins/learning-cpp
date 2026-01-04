#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <random>

namespace Constants {
constexpr int tries = 7;
constexpr int mtSeeds = 10;
constexpr int minRndRange = 1;
constexpr int maxRndRange = 100;
} // namespace Constants

namespace {
void printStartPrompt() {
    std::cout << "Let's play a game. I'm thinking of a number between " << Constants::minRndRange
              << " and " << Constants::maxRndRange << " . You have " << Constants::tries
              << " tries to guess what it is.\n";
}

inline void ignoreLine() { std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); }

bool clearFailedExtraction() {
    if (!std::cin) {
        if (std::cin.eof()) {
            std::exit(1);
        }

        std::cin.clear();
        ignoreLine();

        return true;
    }

    return false;
}

int getUserGuess(int triesAttempted) {
    int input{};

    while (true) {
        std::cout << "Guess #" << triesAttempted << ": ";
        std::cin >> input;

        if (clearFailedExtraction()) {
            std::cout << "Invalid number!\n";
            continue;
        }

        if (input < Constants::minRndRange || input > Constants::maxRndRange) {
            std::cout << "Invalid number! Needs to be between " << Constants::minRndRange << " and "
                      << Constants::maxRndRange << ".\n";
            continue;
        }

        ignoreLine();
        return input;
    }
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
    const int rndNum =
        std::uniform_int_distribution{Constants::minRndRange, Constants::maxRndRange}(mt);

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
} // namespace

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

            if (clearFailedExtraction()) {
                continue;
            }
            ignoreLine();

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
