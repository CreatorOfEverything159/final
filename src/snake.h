#ifndef SIGNALSIMULATION_SNAKE_H
#define SIGNALSIMULATION_SNAKE_H
#include <queue>
#include <tuple>
#include <random>
#include "object.h"
#include "box.h"


typedef std::tuple<short, short> Vector;


class Snake : public Object {
protected:
    unsigned int length;
    Vector vector;
    Box* box = nullptr;
    char scales = '+';
    void changeVector();
    virtual bool act() = 0;
    void set(Coordinate pos);
    Coordinate getTheWayOut(Coordinate pos);
    std::queue<Coordinate> body;
public:
    explicit Snake(int priority, unsigned int length = 1);
    ~Snake();
    void putInTheBox(Box &b, Coordinate pos = Coordinate(1, 1));
    void takeOutFromTheBox();
    bool move();

    void clear();
};


#endif
