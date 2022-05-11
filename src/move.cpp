#include "../includes/move.hpp"

Move::Move (Vec2D<int> origin, Vec2D<int> target) {
    this->origin = origin;
    this->target = target;
}