#include "snakes.h"


bool MaizeSnake::act() {
    Coordinate head = body.back();
    if (rand() % 100 < 50) {
        changeVector();
    }
    get<0>(head) += get<0>(vector);
    get<1>(head) += get<1>(vector);
    if (box->getObject(head) >= priority) {
        head = getTheWayOut(body.back());
        if (head == body.back()) {
            return false;
        }
    }
    if (body.size() == length) {
        Coordinate back = body.front();
        box->clear(back);
        body.pop();
    }
    body.push(head);
    box->paint(head, scales, priority);
    Box::update();
    return true;
}
