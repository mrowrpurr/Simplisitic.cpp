#pragma once

#include <string_format.h>

#include "Point.h"
#include "Vec3.h"
#include "sreal.h"

namespace Simp1e {
    class Position : public Vec3<sreal> {
    public:
        struct Params {
            sreal x;
            sreal y;
            sreal z;
        };

        Position() = default;
        Position(sreal x, sreal y, sreal z = 0) : Vec3(x, y, z) {}
        Position(const Params& params) : Vec3(params.x, params.y, params.z) {}

        virtual Point ToPoint() const { return Point(x(), y()); }

        virtual sreal x() const { return one(); }
        virtual sreal y() const { return two(); }
        virtual sreal z() const { return three(); }

        virtual void SetX(sreal x) { SetOne(x); }
        virtual void SetY(sreal y) { SetTwo(y); }
        virtual void SetZ(sreal z) { SetThree(z); }

        virtual bool operator==(const Position& other) const {
            return x() == other.x() && y() == other.y() && z() == other.z();
        }

        std::string ToString() const { return string_format("Position({}, {}, {})", x(), y(), z()); }
        operator std::string() const { return ToString(); }
    };
}
