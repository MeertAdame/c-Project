//
// Created by Adame Meert on 09/03/2023.
//

#include "position.h"



position::position(int x_, int y_) : x(x_), y(y_)
{}

position::position() : x(0) ,y(0)
{}

int position::getX() const
{
    return x;
}

int position::getY() const
{
    return y;
}

position position::nextPos(Direction dir) const {
    int newX = x;
    int newY = y;

    switch (dir) {
        case Direction::RIGHT :
            newX += 1;
            break;
        case Direction::LEFT:
            newX -= 1;
            break;
        case Direction::UP:
            newY -= 1;
            break;
        case Direction::DOWN:
            newY += 1;
            break;
        case Direction::STOP:
            break;
    }

    return position(newX, newY);
}

bool position::operator==(const position &other) const {
    return x == other.x && y == other.y;
}









