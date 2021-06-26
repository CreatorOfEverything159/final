#include "snake.h"


Snake::Snake(int priority, unsigned int length) : Object(priority) {
    this->length = length ? length : 1;
}

Snake::~Snake() {
    takeOutFromTheBox();
}

void Snake::putInTheBox(Box &b, Coordinate pos) {
    takeOutFromTheBox();
    box = &b;
    body.push(pos);
    set(pos);
    changeVector();
    for (unsigned int i = 0; i < length; ++i) {
        move();
    }
}

void Snake::takeOutFromTheBox() {
    if (box != nullptr) {
        clear();
    }
}

bool Snake::move() {
    if (box != nullptr) {
        return act();
    }
    return false;
}

void Snake::changeVector() {
    do {
        vector = Vector(random() % 3 - 1, random() % 3 - 1);  // vector(-1 .. 1, -1 .. 1)
    } while (get<0>(vector) == 0 && get<1>(vector) == 0);
}

void Snake::set(Coordinate pos) {
    if (box->getObject(pos) < priority) {
        box->paint(pos, scales, 0);
    }
}

Coordinate Snake::getTheWayOut(Coordinate pos) {
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }
            Coordinate wayOut(get<0>(pos) + i, get<1>(pos) + j);
            if (box->getObject(wayOut) < priority) {
                vector = Vector(i, j);
                return wayOut;
            }
        }
    }
    return pos;
}

void Snake::clear() {
    unsigned int size = body.size();
    for (unsigned int i = 0; i < size; ++i) {
        box->clear(body.front());
        body.pop();
    }
}