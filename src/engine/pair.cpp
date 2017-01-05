#include "pair.hpp"
#include <cmath>


Pair::Pair(double x, double y) : x(x), y(y) {}

////////////////////
// MISC OPERATORS //
////////////////////

double Pair::euclid() {
    return sqrt(x * x + y * y);
}

double Pair::euclidSquared() {
    return x * x + y * y;
}


///////////////////////////////////
// ARITHMATIC PAIRWISE OPERATORS //
///////////////////////////////////

Pair Pair::operator+(const Pair & p) const {
    return Pair(x + p.x, y + p.y);
}

Pair Pair::operator-(const Pair & p) const {
    return Pair(x - p.x, y - p.y);
}

Pair Pair::operator*(const Pair & p) const {
    return Pair(x * p.x, y * p.y);
}

Pair Pair::operator/(const Pair & p) const {
    return Pair(x / p.x, y / p.y);
}

Pair Pair::operator^(const Pair & exp) const {
    return Pair(pow(x, exp.x), pow(y, exp.y));
}


/////////////////////////////////
// ARITHMATIC SCALAR OPERATORS //
/////////////////////////////////

Pair Pair::operator+(const double z) const {
    return Pair(x + z, y + z);
}

Pair Pair::operator-(const double z) const {
    return Pair(x - z, y - z);
}

Pair Pair::operator*(const double z) const {
    return Pair(x * z, y * z);
}

Pair Pair::operator/(const double z) const {
    return Pair(x / z, y / z);
}

Pair Pair::operator^(const double exp) const {
    return Pair(pow(x, exp), pow(y, exp));
}




////////////////////////
// MUTATION OPERATORS //
////////////////////////

void Pair::operator+=(const Pair & p) {
    x+=p.x;
    y+=p.y;
}

void Pair::operator-=(const Pair & p) {
    x-=p.x;
    y-=p.y;
}

void Pair::operator*=(const Pair & p) {
    x*=p.x;
    y*=p.y;
}

void Pair::operator/=(const Pair & p) {
    x/=p.x;
    y/=p.y;
}

void Pair::operator^=(const Pair & exp) {
    x = pow(x, exp.x);
    y = pow(y, exp.y);
}

void Pair::operator^=(const double exp) {
    x = pow(x, exp);
    y = pow(y, exp);
}





