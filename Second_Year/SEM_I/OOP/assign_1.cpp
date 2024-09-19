// ======================================================================
// Name        : assign_1.cpp
// Author      : Omkar Sonawane
// Description : This program implements a Complex class for representing
//               complex numbers, providing operations for addition, 
//               multiplication, and input/output.
// ======================================================================

#include <iostream>
using namespace std;

class Complex {
    double real, imag;

public:
    Complex() : real(0), imag(0) {}

    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload operator* to multiply two complex numbers
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
                       real * other.imag + imag * other.real);
    }

    // Overload operator<< for output
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
        return os;
    }

    // Overload operator>> for input
    friend istream& operator>>(istream& is, Complex& c) {
        char plusMinus, i;
        is >> c.real >> plusMinus >> c.imag >> i; // e.g., 3 + 4i
        if (plusMinus == '-') {
            c.imag = -c.imag;
        }
        return is;
    }
};

int main() {
    Complex c1, c2;
    
    cout << "Enter first complex number (format: a + bi): ";
    cin >> c1;
    
    cout << "Enter second complex number (format: a + bi): ";
    cin >> c2;

    Complex sum = c1 + c2;
    Complex product = c1 * c2;

    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;

    return 0;
}
