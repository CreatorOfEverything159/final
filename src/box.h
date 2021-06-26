#ifndef SIGNALSIMULATION_BOX_H
#define SIGNALSIMULATION_BOX_H
#include "object.h"
#include "area.h"


enum BoxElements {
    EMPTY_SPACE = 0,
    BORDER = 2
};


class Box : public Area {
private:
    int** box;
    void draw(Coordinate pos, char c, int priority) const;
public:
    Box(unsigned int x0, unsigned int y0, unsigned int width, unsigned int height);
    ~Box();
    int getObject(Coordinate pos);
    void paint(Coordinate pos, char c, int priority) const;
    void clear(Coordinate pos) const override;
    void clear() override;

    void paintBorders();
};


#endif
