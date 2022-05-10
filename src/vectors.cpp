#include "../includes/vectors.hpp"

template <typename T>
Vec2D<T>::Vec2D() {
    this->x = (T) 0;
    this->y = (T) 0;
}

template <typename T>
Vec2D<T>::Vec2D(T x, T y) {
    this->x = x;
    this->y = y;
}

template <typename T>
Vec2D<T>::~Vec2D() {
    if (std::is_pointer<T>::value) {
        free((void*)x);
        free((void*)y);
    }
}
