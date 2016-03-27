#ifndef __ENGINE_PAIR
#define __ENGINE_PAIR

class Pair {
public:
    double x;
    double y;

    double euclid();

    Pair(double x, double y);

    // TODO implement the quake fast inverse sqrt
    // double euclidApprox();
    double euclidSquared();

    Pair operator+(const Pair & p);
    Pair operator-(const Pair & p);
    Pair operator*(const Pair & p);
    Pair operator/(const Pair & p);
    
    void operator+=(const Pair & p);
    void operator-=(const Pair & p);
    void operator*=(const Pair & p);
    void operator/=(const Pair & p);
};

#endif
