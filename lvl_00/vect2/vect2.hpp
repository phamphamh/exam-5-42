#pragma once
#include <iostream>

struct vect2 {
    int _x, _y;

    vect2(int x = 0, int y = 0) : _x(x), _y(y) {}
    vect2(const vect2& o) : _x(o._x), _y(o._y) {}
    vect2& operator=(const vect2& o) { _x = o._x; _y = o._y; return *this; }

    int& operator[](int i) { return i ? _y : _x; }
    int operator[](int i) const { return i ? _y : _x; }

    vect2 operator+(int i) const { return vect2(_x + i, _y + i); }
    vect2 operator*(int i) const { return vect2(_x * i, _y * i); }
    vect2 operator+(const vect2& v) const { return vect2(_x + v._x, _y + v._y); }
    vect2 operator*(const vect2& v) const { return vect2(_x * v._x, _y * v._y); }

    vect2 operator++(int) { vect2 tmp(*this); _x++; _y++; return tmp; }
    vect2& operator++() { _x++; _y++; return *this; }
    vect2 operator--(int) { vect2 tmp(*this); _x--; _y--; return tmp; }
    vect2& operator--() { _x--; _y--; return *this; }

    bool operator==(const vect2& v) const { return _x == v._x && _y == v._y; }
    bool operator!=(const vect2& v) const { return !(*this == v); }

    vect2& operator+=(int i) { _x += i; _y += i; return *this; }
    vect2& operator*=(int i) { _x *= i; _y *= i; return *this; }
    vect2& operator+=(const vect2& v) { _x += v._x; _y += v._y; return *this; }
    vect2& operator*=(const vect2& v) { _x *= v._x; _y *= v._y; return *this; }

    void print() const { std::cout << "(" << _x << ", " << _y << ")" << std::endl; }
};
