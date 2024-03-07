#include "points.h"

void Points::addPoints(Values value) {
    this->points += value;
}

int Points::getPoints() {
    return this->points;
}

void Points::resetPoints() {
    this->points = 0;
}