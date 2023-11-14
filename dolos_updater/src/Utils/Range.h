#ifndef RANGE_H
#define RANGE_H

class Range {
private:
    int lower;
    int upper;

public:
    Range(int lower, int upper);
    void setLower(int lower);
    int getLower() const;
    void setUpper(int upper);
    int getUpper() const;
};

#endif // RANGE_H
