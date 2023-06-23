#pragma once

#include "sreal.h"

namespace Simp1e {
    class Point {
        sreal _x = 0;
        sreal _y = 0;

    public:
        struct Params {
            sreal x;
            sreal y;
        };

        Point() = default;
        Point(sreal x, sreal y) : _x(x), _y(y) {}
        Point(const Params& params) : _x(params.x), _y(params.y) {}

        virtual sreal& x() { return _x; }
        virtual sreal& y() { return _y; }

        virtual const sreal& x() const { return _x; }
        virtual const sreal& y() const { return _y; }

        bool operator==(const Point& other) const { return _x == other._x && _y == other._y; }
    };
}
