#ifndef SHAPE_HPP_
#define SHAPE_HPP_
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

// 通过在基类中定义虚函数，可以实现动态绑定，
// 使得基类指针或引用可以调用派生类的实现，从而实现多态。
// 定义为抽象类要求子类必须重写
class Shape
{
public:
    explicit Shape();
    virtual ~Shape();
    // 定义为抽象类 -- > 支持显式接口功能
    // 定义为虚函数的作用 -- > 支持运行多态
    // 含有至少一个纯虚函数
    virtual double area() = 0;
};

Shape::Shape()
{
    cout << __FUNCTION__ << " Hello from abstract class constructor! " << endl;
}

Shape::~Shape()
{
    cout << __FUNCTION__ << " Hello from abstract class destructor! " << endl;
};

class Rectangle : public Shape
{
private:
    double width, length;

public:
    Rectangle(double w, double l);
    virtual ~Rectangle();
    virtual double area() override
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
    double area() override
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