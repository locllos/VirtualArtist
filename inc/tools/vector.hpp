#pragma once
#include <math.h>

const float PI = 4 * atan(1);

template <typename elem_t>
class Vector2
{
public:
    
    elem_t x;
    elem_t y;

public:

    Vector2() : x(0), y(0) {};
    Vector2(elem_t x_component, elem_t y_component) : x(x_component), y(y_component) {}
    Vector2(const Vector2& copy_vector) : x(copy_vector.x), y(copy_vector.y) {}

    void mulXY(elem_t x_factor, elem_t y_factor)
    {
        x *= x_factor;
        y *= y_factor;
    }

    void xy(elem_t x, elem_t y)
    {
        this->x = x;
        this->y = y;
    }

    virtual elem_t getLength() const
    {
        return sqrt(x * x + y * y);
    }
    virtual elem_t getSquaredLength() const
    {
        return (x * x + y * y);
    }

    elem_t getAngle() const
    {
        elem_t length = getLength();

        return length > 0 ? acos(x / getLength()) : PI / 2
    }

    Vector2& operator=(const Vector2& copy_vector)
    {
        x = copy_vector.x;
        y = copy_vector.y;

        return *this;
    }

    bool operator==(const Vector2& rhs_vector) const
    {
        return (x == rhs_vector.x && y == rhs_vector.y);
    }

    bool operator!=(const Vector2& rhs_vector) const
    {
        return (!this->operator==(rhs_vector));  
    }
    
    Vector2& operator*=(elem_t scalar)
    {
        xy(x * scalar, y * scalar);

        return *this;
    }

    Vector2& operator/=(elem_t scalar)
    {
        xy(x / scalar, y / scalar);

        return *this;
    }

    Vector2& operator+=(const Vector2& rhs_vector)
    {
        xy(x + rhs_vector.x, y + rhs_vector.y);

        return *this;
    }

    Vector2& operator-=(const Vector2& rhs_vector)
    {
        xy(x - rhs_vector.x, y - rhs_vector.y);

        return *this;
    }

    Vector2 operator+(const Vector2& rhs_vector) const
    {
        Vector2 result_vector(x, y);

        result_vector += rhs_vector;

        return result_vector;
    }

    Vector2 operator-(const Vector2& rhs_vector) const
    {
        Vector2 result_vector(x, y);

        result_vector -= rhs_vector;

        return result_vector;
    }

    elem_t operator*(const Vector2& rhs_vector) const
    {
        return (x * rhs_vector.x + y * rhs_vector.y);
    }

    Vector2 operator*(elem_t scalar) const
    {
        return Vector2(x * scalar, y * scalar);
    }
    
    void Rotate(elem_t angle)
    {
        elem_t sina = sin(rotation_angle);
        elem_t cosa = cos(rotation_angle);

        elem_t x_component = x;
        elem_t y_component = y;

        x = x_component * cosa - y_component * sina;
        y = x_component * sina + y_component * cosa;    
    }

    virtual void Normalize()
    {
        elem_t length = getLength();

        this->operator/=(length);
    }

    ~Vector2() = default;

};