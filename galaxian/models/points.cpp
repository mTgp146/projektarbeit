#include "points.h"
#include <cstdio>
#include <string>

void Points::addPoints(Values value) {
    this->points += value;
}

int Points::getPoints() {
    return this->points;
}

void Points::resetPoints() {
    this->points = 0;
}

int Points::getHighscore() {
    return this->highscore;
}

void Points::setHighscore(int highscore) {
    this->highscore = highscore;
}

void Points::setHighscore() {
    this->highscore = points;
}