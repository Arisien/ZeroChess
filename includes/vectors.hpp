#ifndef ZERO_VECTORS_HPP
#define ZERO_VECTORS_HPP

#include <type_traits>

template <typename T>
class Vec2D {
    public:
        T x;
        T y;
        Vec2D();
        Vec2D(T x, T y);
        ~Vec2D();
};

#endif