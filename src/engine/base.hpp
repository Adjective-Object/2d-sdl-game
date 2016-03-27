#ifndef __ENGINE_BASE
#define __ENGINE_BASE

class Pair {
public:
    double x;
    double y;
    double length();
    Pair operator+(const Pair & p);
    Pair operator-(const Pair & p);
    Pair operator*(const Pair & p);
    Pair operator/(const Pair & p);
};

#endif
