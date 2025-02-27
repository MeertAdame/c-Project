//
// Created by Adame Meert on 22/03/2023.
//

#include "elem.h"

elem::elem(Element e, ElementType t)
    : value(e), type(t)
{}

elem::elem() : value(Element::EMPTY) ,type(ElementType::ELEMENT)
{}

ElementType elem::getType() const
{
    return type;
}

Element elem::getValue() const
{
    return value;
}

std::ostream& operator<< (std::ostream& os, const elem& el)
{
    os << " value : " << el.getValue();
    return os;
}

bool elem::operator==(const elem& other) const {
    return value == other.value && type == other.type;
}

bool elem::operator!=(const elem& other) const {
    return value != other.value && type == other.type;
}
