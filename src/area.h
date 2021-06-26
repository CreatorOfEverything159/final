#ifndef SIGNALSIMULATION_AREA_H
#define SIGNALSIMULATION_AREA_H
#include <tuple>


typedef std::tuple<unsigned int, unsigned int> Coordinate;


class Area {
protected:
    unsigned int x0;
    unsigned int y0;
    unsigned int width;
    unsigned int height;
    char** area;
    void draw(Coordinate pos, char c) const;
    [[nodiscard]] bool isIncludes(Coordinate pos) const;
public:
    const char CLEAR = ' ';
    Area(unsigned int x0, unsigned int y0, unsigned int width, unsigned int height);
    ~Area();
    void paint(Coordinate pos, char c) const;

    virtual void clear(Coordinate pos) const;

    virtual void clear();
    static void update();
};


#endif
