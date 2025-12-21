#include <iomanip>
#include <iostream>

double getUserHeight() {
    double height{};

    std::cout << "Enter the height of the tower in metres: ";
    std::cin >> height;

    return height;
}

double distanceFallen(double start, double time) { return 9.8 * (time * time) / 2; }

void displayHeight(int time, double height) {
    if (height <= 0) {
        std::cout << "At " << time << " seconds, the ball is on the ground.";
    } else {
        std::cout << "At " << time << " seconds, the ball is at height: " << height << " metres\n";
    }
}

int main() {
    double height{getUserHeight()};

    // INFO: Deliberate non-use of loops is used here
    displayHeight(0, height);
    displayHeight(1, height - distanceFallen(height, 1));
    displayHeight(2, height - distanceFallen(height, 2));
    displayHeight(3, height - distanceFallen(height, 3));
    displayHeight(4, height - distanceFallen(height, 4));
    displayHeight(5, height - distanceFallen(height, 5));

    return 0;
}
