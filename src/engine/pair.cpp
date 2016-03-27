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


//////////////////////////
// ARITHMATIC OPERATORS //
//////////////////////////

Pair Pair::operator+(const Pair & p) {
   return Pair(x + p.x, y + p.y);
}

Pair Pair::operator-(const Pair & p) {
   return Pair(x - p.x, y - p.y);
}

Pair Pair::operator*(const Pair & p) {
   return Pair(x * p.x, y * p.y);
}

Pair Pair::operator/(const Pair & p) {
   return Pair(x / p.x, y / p.y);
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

