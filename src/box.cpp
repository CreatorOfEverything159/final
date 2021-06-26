#include "box.h"


Box::Box(unsigned int x0, unsigned int y0, unsigned int width, unsigned int height) : Area(
        x0, y0, width > 2 ? width : 3,height > 2 ? height : 3) {
    this->box = new int*[this->width];
    for (unsigned int i = 0; i < this->width; ++i) {
        this->box[i] = new int[this->height];
        for (unsigned int j = 0; j < this->height; ++j) {
            this->box[i][j] = BoxElements::EMPTY_SPACE;
        }
    }
    paintBorders();
    update();
}

void Box::paintBorders() {
    // Ставим границы на углах
    paint(Coordinate(1, 1), '+', BoxElements::BORDER);
    paint(Coordinate(this->width, 1), '+', BoxElements::BORDER);
    paint(Coordinate(1, this->height), '+', BoxElements::BORDER);
    paint(Coordinate(this->width, this->height), '+', BoxElements::BORDER);
    // Обводка сверху и снизу
    for (unsigned int i = 1; i < this->width - 1; ++i) {
        paint(Coordinate(i + 1, 1), '-', BoxElements::BORDER);
        paint(Coordinate(i + 1, this->height), '-', BoxElements::BORDER);
    }
    // Обводка слева и справа
    for (unsigned int i = 1; i < this->height - 1; ++i) {
        paint(Coordinate(1, i + 1), '|', BoxElements::BORDER);
        paint(Coordinate(this->width, i + 1), '|', BoxElements::BORDER);
    }
}

Box::~Box() {
    Area::~Area();
    for (unsigned int i = 0; i < width; ++i) {
        delete[] this->box[i];
    }
    delete[] this->box;
}

int Box::getObject(Coordinate pos) {
    return box[get<0>(pos) - 1][get<1>(pos) - 1];
}

void Box::draw(Coordinate pos, char c, int priority) const {
    Area::draw(pos, c);
    box[get<0>(pos) - 1][get<1>(pos) - 1] = priority;
}

void Box::paint(Coordinate pos, char c, int priority) const {
    if (isIncludes(pos)) draw(pos, c, priority);
}

void Box::clear(Coordinate pos) const {
    if (isIncludes(pos)) draw(pos, CLEAR, BoxElements::EMPTY_SPACE);
}

void Box::clear() {
    for (unsigned int x = 1; x <= width; ++x) {
        for (unsigned int y = 1; y <= height; ++y) {
            draw(Coordinate(x, y), CLEAR, BoxElements::EMPTY_SPACE);
        }
    }
    paintBorders();
    update();
}
