#include "shape.hpp"

int main(int argc, char const *argv[])
{
    Shape *graphic = new Rectangle(2, 3);
    cout << "The shape's area is " << graphic->area() << endl;
    graphic = new Circle(2);
    cout << "The shape's area is " << graphic->area() << endl;
    graphic = new Square(3);
    cout << "The shape's area is " << graphic->area() << endl;
    delete graphic;
    // two versions of implementation
    // cout << "Rectangle:" << endl;
    // Rectangle rectangle(1, 10);
    // cout << "Area of rectangle is: " << rectangle.area() << endl;
    // cout << "Square:" << endl;
    // Square square(10);
    // cout << "Area of square is: " << square.area() << endl;
    // cout << "Circle:" << endl;
    // Circle circle(10);
    // cout << "Area of circle is: " << circle.area() << endl;
    return 0;
}
