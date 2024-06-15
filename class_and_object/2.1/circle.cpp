#include "circle.hpp"

int main()
{
    circle c0, c1;
    c0.init();
    // getchar();
    c1.init();
    bool isIntersect = c0.judgeIntersection(c1);
    if (isIntersect)
        std::cout << "They intersects with each other." << std::endl;
    else
        std::cout << "They are too far from each other." << std::endl;
    // system("pause");
    return 0;
}