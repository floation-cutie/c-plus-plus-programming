#include <bits/stdc++.h>
using namespace std;

class A
{
private:
    int id;
    int *buffer;

public:
    A()
    {
        id = 0;
        cout << id << " construct!" << endl;
        buffer = new int[10];
    }
    // A(const A &a)
    // {
    //     this->id = a.id;
    //     cout << id << "copy construct!" << endl;
    // }

    ~A()
    {
        delete[] buffer;
        cout << id << " deconstruct!" << endl;
    }
};

int main()
{
    A a{};
    // not ok
    A b = a;
    // not ok
    A c(a);

    return 0;
}
