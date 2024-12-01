#include <iostream>
#include <cstring>
using namespace std;

class Number {
    int counter;
public:
    Number() : counter(0) {}

    Number operator++() {
        counter++;
        return *this;
    }

    // this will work fine
    Number operator+() {
        counter++;
        return *this;
    }

    int getCount() { return counter;}
};

int main() {

    Number abc;

    cout << abc.getCount() << endl;
    ++abc;
    +abc;
    cout << abc.getCount() << endl;

    return 0;
}