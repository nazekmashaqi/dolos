#include "Range.h"

Range::Range(int lower, int upper) : lower(lower), upper(upper) {}

void Range::setLower(int lower) {
    this->lower = lower;
}

int Range::getLower() const {
    return lower;
}

void Range::setUpper(int upper) {
    this->upper = upper;
}

int Range::getUpper() const {
    return upper;
}
