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

    // pairwise new product ops
    Pair operator+(const Pair & p) const;
    Pair operator-(const Pair & p) const;
    Pair operator*(const Pair & p) const;
    Pair operator/(const Pair & p) const;
    Pair operator^(const Pair & exp) const;

    // scalar new product ops
    Pair operator+(const double x) const;
    Pair operator-(const double x) const;
    Pair operator*(const double x) const;
    Pair operator/(const double x) const;
    Pair operator^(const double exp) const;
   
    // pairwise mutation ops
    void operator+=(const Pair & p);
    void operator-=(const Pair & p);
    void operator*=(const Pair & p);
    void operator/=(const Pair & p);
    void operator^=(const Pair & exp);
    void operator^=(const double exp);
};

#endif
