#include "collisiondatum.hpp"

std::ostream& operator<<(std::ostream& strm, const CollisionDatum& p);{
    return strm << "CollisionDatum( "
        << "position = " << position
        << ")";
}