#include <iostream>
#include <cmath>
#include "pair.hpp"

Pair::Pair() {}
Pair::Pair(double x, double y) : x(x), y(y) {}

////////////////////
// MISC OPERATORS //
////////////////////

double Pair::euclid() const {
    return sqrt(x * x + y * y);
}

double Pair::euclidSquared() const {
    return x * x + y * y;
}

///////////////////////////////////
// ARITHMATIC PAIRWISE OPERATORS //
///////////////////////////////////

Pair Pair::operator+(const Pair& p) const {
    return Pair(x + p.x, y + p.y);
}

Pair Pair::operator-(const Pair& p) const {
    return Pair(x - p.x, y - p.y);
}

Pair Pair::operator*(const Pair& p) const {
    return Pair(x * p.x, y * p.y);
}

Pair Pair::operator/(const Pair& p) const {
    return Pair(x / p.x, y / p.y);
}

Pair Pair::operator^(const Pair& exp) const {
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

void Pair::operator+=(const Pair& p) {
    x += p.x;
    y += p.y;
}

void Pair::operator-=(const Pair& p) {
    x -= p.x;
    y -= p.y;
}

void Pair::operator*=(const Pair& p) {
    x *= p.x;
    y *= p.y;
}

void Pair::operator/=(const Pair& p) {
    x /= p.x;
    y /= p.y;
}

void Pair::operator^=(const Pair& exp) {
    x = pow(x, exp.x);
    y = pow(y, exp.y);
}

void Pair::operator^=(const double exp) {
    x = pow(x, exp);
    y = pow(y, exp);
}

void Pair::operator*=(const double factor) {
    x = x * factor;
    y = y * factor;
}

void Pair::operator/=(const double factor) {
    x = x / factor;
    y = y / factor;
}

/////////////////
// COMPARATORS //
/////////////////

#define EPSILON 0.00001
bool Pair::operator==(const Pair& p) const {
    return fabs(p.x - x) < EPSILON && fabs(p.y - y) < EPSILON;
}

bool Pair::operator!=(const Pair& p) const {
    return !(*this == p);
}

/////////////
// PRINTER //
/////////////

std::ostream& operator<<(std::ostream& strm, const Pair& p) {
    return strm << "Pair(" << p.x << ", " << p.y << ")";
}
