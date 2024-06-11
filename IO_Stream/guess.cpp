#include <cmath>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{

    // Seed with a real random value, if available
    std::random_device r;

    // Choose a random mean between 1 and 1000
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 1001);
    int ans = uniform_dist(r);

    while (true)
    {
        cout << "Guess the number: " << endl;
        // Handle input
        string line;
        int input;
        char rubbish;
        if (!getline(cin, line))
            throw domain_error("Can\'t read this line");
        istringstream iss(line);
        if (!(iss >> input && !(iss >> rubbish)))
        {
            cout << "Wrong input! " << endl;
            continue;
        }
        if (input < 0 || input > 1000)
            cout << "Illegal number." << endl;
        else if (input == ans)
        {
            cout << "You win the game!" << endl;
            break;
        }
        else if (input > ans)
            cout << "Input too big." << endl;
        else
            cout << "Input too little." << endl;
    }
    return 0;
}
