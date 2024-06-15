#ifndef SHAPE_HPP_
#define SHAPE_HPP_
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

// 如果基类中的方法不是虚函数，
// 派生类中的同名方法不能通过基类指针或引用调用，
// 这会导致静态绑定，无法实现多态。

class Shape
{
public:
    explicit Shape();
    virtual ~Shape();
    double area();
};

Shape::Shape()
{
    cout << __FUNCTION__ << " Hello from abstract class constructor! " << endl;
}

Shape::~Shape()
{
    cout << __FUNCTION__ << " Hello from abstract class destructor! " << endl;
};

double Shape::area()
{
    std::cout << "\nTry to compute area for the shape" << std::endl;
    return 0;
}
class Rectangle : public Shape
{
private:
    double width, length;

public:
    Rectangle(double w, double l);
    virtual ~Rectangle();
    // virtual double area() override
    // {
    //     return width * length;
    // }
    double area()
    {
        return width * length;
    }
};

// 基类可以进行隐式调用
Rectangle::Rectangle(double w, double l) : Shape(), width(w), length(l)
{
    cout << __FUNCTION__ << " Hello from rectangle constructor! " << endl;
}

Rectangle::~Rectangle()
{
    cout << __FUNCTION__ << " Hello from rectangle destructor! " << endl;
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r);
    virtual ~Circle();
    //     double area() override
    //     {
    //         return M_PI * radius * radius;
    // #undef _USE_MATH_DEFINES
    //     }
    double area()
    {
        return M_PI * radius * radius;
#undef _USE_MATH_DEFINES
    }
};

Circle::Circle(double r) : radius(r)
{
    cout << __FUNCTION__ << " Hello from circle constructor! " << endl;
}

Circle::~Circle()
{
    cout << __FUNCTION__ << " Hello from circle constructor! " << endl;
}

class Square : public Rectangle
{
public:
    Square(double l);
    virtual ~Square();
};

Square::Square(double l) : Rectangle(l, l)
{
    cout << __FUNCTION__ << " Hello from square constructor! " << endl;
}

Square::~Square()
{
    cout << __FUNCTION__ << " Hello from square destructor! " << endl;
}

#endif