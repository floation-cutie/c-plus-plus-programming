#ifndef CIRCLE
#define CIRCLE
#include <iostream>
#include <cmath>
/**
 * 本文件缺省了拷贝构造函数
 * 故而会出现显式地析构函数次数更多的情形
 * 实际上是两次对象作为函数参数，并没有明确地表现出来
 */

// Point class use inline to implement
class Point
{
private:
    double x, y;

public:
    // initialized list delcaration which is useful in creating const object
    explicit Point(double _x = 0, double _y = 0) : x(_x), y(_y)
    {
        std::cout << __FUNCTION__ << " constructor being called." << std::endl;
    };
    // implement two interfaces
    double distance(const Point &from, const Point &to)
    {
        return sqrt((from.x - to.x) * (from.x - to.x) +
                    (from.y - to.y) * (from.y - to.y));
    };
    double distance(const Point &that)
    {
        return sqrt((this->x - that.x) * (this->x - that.x) +
                    (this->y - that.y) * (this->y - that.y));
    }
    ~Point()
    {
        std::cout << __FUNCTION__ << " destructor being called." << std::endl;
    }
};

class circle
{
private:
    Point center;
    double radius;

public:
    circle(double x, double y, double radius);
    void init();
    bool judgeIntersection(const circle &another) const;
    double getRad() const { return radius; };
    // 此处返回的不是引用，所以会调用拷贝构造函数
    Point getCenter() const { return center; };
    ~circle();
};

inline circle::circle(double x = 0, double y = 0, double r = 0) : center(Point(x, y)), radius(r)
{
    std::cout << __FUNCTION__ << " constructor being called." << std::endl;
}

void circle::init()
{
    std::cout << "Input coordinate i.e. x && y, then input radius r" << std::endl;
    double x, y;
    std::cin >> x >> y >> radius;
    center = Point(x, y);
}
inline circle::~circle()
{
    std::cout << __FUNCTION__ << " destructor being called." << std::endl;
}

// 常量引用，所以不会调用拷贝构造函数
bool circle::judgeIntersection(const circle &another) const
{
    double sumRad = this->getRad() + another.getRad();
    // 此处会调用两次Point 拷贝构造函数
    double dis = this->getCenter().distance(another.getCenter());
    return dis <= sumRad;
};
#endif