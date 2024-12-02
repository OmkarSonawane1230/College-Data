#include <iostream>
using namespace std;

class Base {
public:
    virtual void play() = 0;

};

class Derived {
public:
    void play() {
        cout << "Hii how are you" << endl;
    }
};

int main() {

    Derived d;
    d.play();

    return 0;
}