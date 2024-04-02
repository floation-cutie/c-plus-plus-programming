#include <bits/stdc++.h>
using namespace std;

class animal
{
    // problem
    // animal(int a)
    // {
    //     cout << "Monkey " << endl;
    // }
};
class monkey : public animal
{
public:
    monkey()
    {
        cout << "Monkey " << endl;
    }
};

class goldenmonkey : public monkey
{
public:
    goldenmonkey()
    {
        cout << "goldenMonkey " << endl;
    }
};
int main(int argc, char const *argv[])
{
    goldenmonkey g;
    return 0;
}
