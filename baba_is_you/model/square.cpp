//
// Created by Adame Meert on 09/03/2023.
//

#include "square.h"

std::ostream& operator <<(std::ostream& os, const square& sq)
{
        std::string str;

        switch (sq.pixel.at(sq.pixel.size()-1).getValue()) {
            case Element::GRASS :
                os << "grass";
                break;
            case Element::TEXT_GRASS :
                os << "text_grass";
                break;
        case Element::FLAG :
            os << "flag";
            break;
        case Element::TEXT_FLAG :
            os << "text_flag";
            break;
            case Element::WALL :
                os << "wall";
                break;
            case Element::TEXT_WALL :
                os << "text_wall";
                break;
            case Element::LAVA :
                os << "lava";
                break;
            case Element::TEXT_LAVA :
                os << "text_lava";
                break;
            case Element::BABA :
                os << "baba";
                break;
            case Element::TEXT_BABA :
                os << "text_baba";
                break;
            case Element::ROCK :
                os << "rock";
                break;
            case Element::TEXT_ROCK :
                os << "text_rock";
                break;
            case Element::BONE:
                os << "bone";
                break;
            case Element::TEXT_BONE :
                os << "text_bone";
                break;
            case Element::GOOP :
                os << "goop";
                break;
            case Element::TEXT_GOOP :
                os << "text_goop";
                break;
            case Element::METAL :
                os << "metal";
                break;
            case Element::TEXT_METAL :
                os << "text_metal";
                break;
            case Element::WIN :
                os << "win";
                break;
            case Element::KILL :
                os << "kill";
                break;
            case Element::SINK :
                os << "sink";
                break;
            case Element::STOP :
                os << "stop";
                break;
            case Element::YOU :
                os << "you";
                break;
            case Element::PUSH :
                os << "push";
                break;
            case Element::BEST :
                os <<  "best";
                break;
            case Element::IS :
                os << "is";
                break;
            case Element::EMPTY :
                os << "   ";
                break;
        case Element::NOTHING :
            os << "   ";
            break;
        }

    return os;
}

square::square(std::vector<elem> elems, position position)
        : pixel(elems), pos(position)
{}

square::square() : pixel(), pos()
{}

std::vector<elem> square::getElements() const
{
    return pixel;
}

void square::push(elem x) {
    pixel.push_back(x);
}

void square::pop() {
    pixel.pop_back();
}

position square::getPosition() const
{
    return pos;
}

