#include <iostream>

void anyname()
{
    std::cout << "Current function: " << __FUNCTION__ << std::endl;
}
class frac
{
public:
    int num, dnum;
    frac(int num, int dnum)
    {
        this->num = num;
        this->dnum = dnum;
    }
};
int main()
{
    anyname();
    const frac a{2, 3};
    return 0;
}
