#ifndef SIGNALSIMULATION_SNAKES_H
#define SIGNALSIMULATION_SNAKES_H
#include "snake.h"


enum SnakeKind {
    PACIFIST = 1,
    GNAWER = 3,
    PREDATOR = 4
};


/** Победитель премии Дарвина - погибает, когда находится в тупике **/
class MaizeSnake : public Snake {
private:
    char scales = '+';
public:
    explicit MaizeSnake(unsigned int length = 1) : Snake(SnakeKind::PACIFIST, length) {};
    bool act() override;
};


/** Дружелюбный удав, но склонен к побегам **/
class RainbowBoa : private Snake {
private:
    char scales = '*';
public:
    explicit RainbowBoa(unsigned int length = 1) : Snake(SnakeKind::GNAWER, length) {};
    bool act() override;
};


/** Африканский смертоносец - убивает любое живое существо на своем пути, кроме себя **/
class BlackMamba : private Snake {
private:
    char scales = '@';
public:
    explicit BlackMamba(unsigned int length = 1) : Snake(SnakeKind::PREDATOR, length) {};
    bool act() override;
};


/** Очень мощная змея - может, что угодно, но очень медленная **/
class Python : private Snake {
private:
    char scales = '%';
    int tick = 0;
    const int TICK = 5;  // хотя должно быть примерно 48
public:
    explicit Python(unsigned int length = 1) : Snake(SnakeKind::PREDATOR, length) {};
    bool act() override;
};


#endif
