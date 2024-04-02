#include "point.hpp"

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    Point a(1, 2);
    Point b(5, 6);
    cout << "a.x is " << a.getX() << " a.y is " << a.getY() << endl;
    a++;
    cout << "a.x is " << a.getX() << " a.y is " << a.getY() << endl;
    ++a;
    cout << "a.x is " << a.getX() << " a.y is " << a.getY() << endl;
    --b;
    cout << "b.x is " << b.getX() << " b.y is " << b.getY() << endl;
    b--;
    cout << "b.x is " << b.getX() << " b.y is " << b.getY() << endl;
    return 0;
}