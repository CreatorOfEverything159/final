#include <cstdio>
#include "area.h"


/** Проверка, что координаты принадлежат площади **/
bool Area::isIncludes(Coordinate pos) const {
    return get<0>(pos) && get<1>(pos) && get<0>(pos) <= width && get<1>(pos) <= height;
}

Area::Area(unsigned int x0, unsigned int y0, unsigned int width, unsigned int height) {
    this->x0 = x0;
    this->y0 = y0;
    this->width = width;
    this->height = height;
    this->area = new char*[width];
    for (unsigned int i = 0; i < width; ++i) {
        this->area[i] = new char[height];
        for (unsigned int j = 0; j < height; ++j) {
            this->area[i][j] = CLEAR;
        }
    }
}

Area::~Area() {
    for (unsigned int i = 0; i < width; ++i) {
        delete[] this->area[i];
    }
    delete[] this->area;
}

void Area::paint(Coordinate pos, char c) const {
    if (isIncludes(pos)) draw(pos, c);
}

void Area::clear(Coordinate pos) const {
    if (isIncludes(pos)) draw(pos, CLEAR);
}

void Area::clear() {
    for (unsigned int x = 1; x <= width; ++x) {
        for (unsigned int y = 1; y <= height; ++y) {
            draw(Coordinate(x, y), CLEAR);
        }
    }
    update();
}

void Area::draw(Coordinate pos, char c) const {
    printf("\e[%d;%dH\e[0A", get<1>(pos) + y0 + 1, get<0>(pos) + x0);
    printf("%c", c);
    area[get<0>(pos) - 1][get<1>(pos) - 1] = c;
}

void Area::update() {
    printf("\n");
}
