#include "matrix.hpp"

int main(int argc, char const *argv[])
{
    std::cout << "Input A1:" << std::endl;
    Matrix a1;
    a1.init();
    std::cout << "Input A2:" << std::endl;
    Matrix a2;
    a2.init();
    std::cout << "A1 is\n"
              << a1 << "\n";
    std::cout << "A2 is\n"
              << a2 << "\n";
    std::cout << "A1 + A2 is\n"
              << a1 + a2 << "\n";
    std::cout << "A1 - A2 is\n"
              << a1 - a2 << "\n";
    auto pA1 = new Matrix(size_t(1), size_t(2));
    auto pA2 = new Matrix(size_t(1), size_t(2));
    auto pA3 = new Matrix(size_t(2), size_t(33)); // Doesn't matter. Won't affect the program

    std::cout << "Input pA1:" << std::endl;
    pA1->init();
    std::cout << "Input pA2:" << std::endl;
    pA2->init();
    std::cout << "pA3 is assigned by pA1 add pA2: \n"
              << "\n";
    *pA3 = *pA1 + *pA2;
    std::cout << "pA3 is: \n"
              << *pA3 << "\n";
    *pA3 = *pA1 - *pA2;
    std::cout << "pA3 is assigned by pA1 sub pA2: \n"
              << "\n";
    std::cout << "pA3 is: \n"
              << *pA3 << "\n";
    delete pA1;
    delete pA2;
    delete pA3;
    return 0;
}
