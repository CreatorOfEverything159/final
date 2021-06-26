#include <iostream>
#include <random>
#include "box.h"
#include "snakes.h"
#include <windows.h>

int main() {
    std::random_device dev;
    std::mt19937 randomizer(dev());

    unsigned int width = 100;
    unsigned int height = 25;

    const int SNAKES = 25;
    MaizeSnake snakes[SNAKES];

    Box box(5, 2, width, height);

    for (auto & snake : snakes) {
        snake = MaizeSnake(randomizer() % 5 + 2);
        snake.putInTheBox(box, Coordinate(randomizer() % (width - 6) + 3, randomizer() % (height - 6) + 3));
    }
    Box::update();

    while (true) {
        for (auto & snake : snakes) {
            if (!snake.move()) {
                snake.clear();
                snake = MaizeSnake(randomizer() % 5 + 2);
                snake.putInTheBox(box, Coordinate(randomizer() % (width - 6) + 3, randomizer() % (height - 6) + 3));
            };
        }
        Box::update();
        Sleep(50);
    }

    return 0;
}
