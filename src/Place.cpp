#include "Place.h"
#include <iostream>

Place::Place()
{
}

Place::~Place()
{
}

Vec2 Place::getPos() const
{
    return pos;
}

void Place::setPos(Vec2 newpos)
{
    pos = newpos;
}
