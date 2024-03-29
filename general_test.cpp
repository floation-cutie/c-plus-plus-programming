#include <iostream>

void anyname()
{
    std::cout << "Current function: " << __FUNCTION__ << std::endl;
}

int main()
{
    anyname();
    return 0;
}
