#pragma once
namespace GameVectors {

    struct Vector2d {
        Vector2d(float new_x, float new_y) : x(new_x), y(new_y) {};

        Vector2d() : Vector2d(0, 0) {};
        float x = 0;
        float y = 0;
    };

    struct IntVector2d {
        IntVector2d(int new_x, int new_y) : x(new_x), y(new_y) {};

        IntVector2d() : IntVector2d(0, 0) {};
        int x = 0;
        int y = 0;
    };

    inline bool operator<(const IntVector2d &lhs, const IntVector2d &rhs) {
        return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y);
    }

    inline bool operator==(const IntVector2d &lhs, const IntVector2d &rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }

    inline IntVector2d operator-(const IntVector2d &lhs, const IntVector2d &rhs) {
        return {lhs.x - rhs.x, lhs.y - rhs.y};
    }

    inline IntVector2d operator+(const IntVector2d &lhs, const IntVector2d &rhs) {
        return {lhs.x + rhs.x, lhs.y + rhs.y};
    }


    inline std::ostream &operator<<(std::ostream &os, const IntVector2d &vec) {
        return os << "(" << vec.x << "," << vec.y << ")";
    }

}