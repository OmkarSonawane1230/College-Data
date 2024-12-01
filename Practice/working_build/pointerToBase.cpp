#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() { 
        cout << "Base Display\n"; 
    }
};

class Derived : public Base {
public:
    void display() override { 
        cout << "Derived Display\n"; 
    }
};

int main() {
    Base* base;
    Derived derived;

    base = &derived;
    base->display();  // Outputs: Derived Display

    return 1;
}
