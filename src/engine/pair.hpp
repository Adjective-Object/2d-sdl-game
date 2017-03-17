#ifndef __ENGINE_PAIR
#define __ENGINE_PAIR

#include <iostream>

class Pair {
   public:
    double x;
    double y;

    double euclid() const;

    Pair();
    Pair(double x, double y);

    // TODO implement the quake fast inverse sqrt
    // double euclidApprox();
    double euclidSquared() const;

    // pairwise new product ops
    Pair operator+(const Pair& p) const;
    Pair operator-(const Pair& p) const;
    Pair operator*(const Pair& p) const;
    Pair operator/(const Pair& p) const;
    Pair operator^(const Pair& exp) const;

    // scalar new product ops
    Pair operator+(const double x) const;
    Pair operator-(const double x) const;
    Pair operator*(const double x) const;
    Pair operator/(const double x) const;
    Pair operator^(const double exp) const;

    // pairwise mutation ops
    void operator+=(const Pair& p);
    void operator-=(const Pair& p);
    void operator*=(const Pair& p);
    void operator/=(const Pair& p);
    void operator^=(const Pair& exp);
    void operator^=(const double exp);
    void operator*=(const double factor);
    void operator/=(const double factor);

    // comparators
    bool operator==(const Pair& p) const;
    bool operator!=(const Pair& p) const;

    // defined solely for ordering in sets
    bool operator<(const Pair& p) const;
};

std::ostream& operator<<(std::ostream& strm, const Pair& p);

#endif
