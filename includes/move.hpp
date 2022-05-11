#ifndef ZERO_MOVE_HPP
#define ZERO_MOVE_HPP

#include "vectors.hpp"

class Move {
    public:
        Vec2D<int> origin;
        Vec2D<int> target;

        Move (Vec2D<int> origin, Vec2D<int> target);
};

#endif