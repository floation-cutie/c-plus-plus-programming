#include <bits/stdc++.h>
using namespace std;

class MyVector : public std::vector<std::string>
{
public:
    MyVector &operator+=(const std::string &element)
    {
        this->push_back(element);
        return *this;
    }
    MyVector &operator+=(const MyVector &other)
    {
        for (const string &val : other)
            this->push_back(val);
        return *this;
    }
};

int main()
{
    MyVector vec;
    vec.push_back("jdas");
    vec.push_back("dasdasjdas");
    (vec += "hello") += "jkl";
    for (const string &s : vec)
        cout << s << endl;
    return 0;
}
