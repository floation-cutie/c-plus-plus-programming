#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include <cmath>
class Point
{
private:
    double x, y;

public:
    // initialized list delcaration which is useful in creating const object
    Point(double _x = 0, double _y = 0) : x(_x), y(_y)
    {
        std::cout << __FUNCTION__ << " constructor being called." << std::endl;
    };
    Point(const Point &other)
    {
        std::cout << __FUNCTION__ << " copy constructor being called." << std::endl;
        x = other.x;
        y = other.y;
    }
    double distance(const Point &that)
    {
        return sqrt((this->x - that.x) * (this->x - that.x) +
                    (this->y - that.y) * (this->y - that.y));
    }
    ~Point()
    {
        std::cout << __FUNCTION__ << " destructor being called." << std::endl;
    }

    double getX() const
    {
        return x;
    }
    double getY() const
    {
        return y;
    }
    /**
     * Those unray operator should be implemented as member function
     * what need to emphasis is that the semantics is a bit different
     * There is no move semantics being used
     */
    // before
    Point &operator++()
    {
        x++;
        return *this;
    };
    // after
    Point operator++(int)
    {
        Point old = *this;
        y++;
        return old;
    };
    Point &operator--()
    {
        x--;
        return *this;
    };
    Point operator--(int)
    {
        Point old = *this;
        y--;
        return old;
    };
};
#endif