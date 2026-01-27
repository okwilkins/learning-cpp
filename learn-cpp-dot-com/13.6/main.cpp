#include <iostream>
#include <optional>
#include <string>

enum class Animal {
    pig,
    chicken,
    goat,
    cat,
    dog,
    duck,
};

constexpr std::optional<std::string_view> getAnimalName(Animal animal) {
    using enum Animal;
    using namespace std::string_view_literals;

    switch (animal) {
    case pig:
        return "pig"sv;
    case chicken:
        return "chicken"sv;
    case goat:
        return "goat"sv;
    case cat:
        return "cat"sv;
    case dog:
        return "dog"sv;
    case duck:
        return "duck"sv;
    default:
        return std::nullopt;
    }
}

constexpr std::optional<int> getNumberOfLegs(Animal animal) {
    using enum Animal;
    switch (animal) {
    case pig:
        return 4;
    case chicken:
        return 2;
    case goat:
        return 4;
    case cat:
        return 4;
    case dog:
        return 4;
    case duck:
        return 2;
    default:
        std::nullopt;
    }
}

int main() {
    constexpr Animal animal{Animal::cat};
    constexpr auto tmp_name{getAnimalName(animal)};
    constexpr auto tmp_legs{getNumberOfLegs(animal)};
    std::string_view name{};
    int legs{};

    if (tmp_name.has_value()) {
        name = tmp_name.value();
    } else {
        return 1;
    }

    if (tmp_legs.has_value()) {
        legs = tmp_legs.value();
    } else {
        return 1;
    }

    std::cout << "A " << name << " has " << legs << " legs.\n";
}
