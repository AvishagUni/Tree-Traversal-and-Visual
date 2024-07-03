#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <cmath>

using namespace std;

class Complex {
public:
    double real;
    double imag;

    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    double get_real() const { return real; }
    double get_imag() const { return imag; }

    // Overload the equality operator
    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }

    bool operator<(const Complex &other) const {
        return sqrt(real * real + imag * imag) < sqrt(other.real * other.real + other.imag * other.imag);
    }

    // Overload the greater-than operator for comparison based on magnitude
    bool operator>(const Complex& other) const {
        return !(*this < other) && !(*this == other);
    }

    // Convert to string for easy display
    std::string toString() const {
        return "(" + std::to_string(real) + ", " + std::to_string(imag) + ")";
    }

    // Overload the << operator for easy printing
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << "(" << c.real << ", " << c.imag << ")";
        return os;
    }
};

#endif // COMPLEX_HPP

#endif // COMPLEX_HPP



