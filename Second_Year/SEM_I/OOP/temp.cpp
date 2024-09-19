#include <iostream>
using namespace std;

class Temp {
    int a, b;
    
public:
    Temp(int x = 90, int y = 100): a(x), b(y) {}

    void printC() {
        cout << "X = " << a << endl;
        cout << "Y = " << b << endl;
    }
};


int main(void) {

    Temp t1 = Temp();
    t1.printC();

    return 0;
}