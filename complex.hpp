// minnesav@gmail.com

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <cmath>

using namespace std;

class Complex {
public:
    double real;
    double imag;

    /**
     * @brief Constructs a Complex object with the given real and imaginary parts.
     *
     * @param r The real part of the complex number. Default value is 0.0.
     * @param i The imaginary part of the complex number. Default value is 0.0.
     */
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    /**
     * @brief Returns the real part of the complex number.
     * 
     * @return The real part of the complex number.
     */
    double get_real() const { return real; }
    /**
     * @brief Get the imaginary part of the complex number.
     * 
     * @return The imaginary part of the complex number.
     */
    double get_imag() const { return imag; }

    // Overload the equality operator
    /**
     * @brief Checks if the current complex number is equal to another complex number.
     * 
     * @param other The complex number to compare with.
     * @return true if the complex numbers are equal, false otherwise.
     */
    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }

    /**
     * @brief Overloaded less than operator for comparing two Complex numbers.
     * 
     * This function compares the magnitude of two Complex numbers and returns true if the magnitude of the current Complex number is less than the magnitude of the other Complex number.
     * 
     * @param other The Complex number to compare with.
     * @return true if the magnitude of the current Complex number is less than the magnitude of the other Complex number, false otherwise.
     */
    bool operator<(const Complex &other) const {
        return sqrt(real * real + imag * imag) < sqrt(other.real * other.real + other.imag * other.imag);
    }

    // Overload the greater-than operator for comparison based on magnitude
    /**
     * @brief Overloaded greater-than operator.
     * 
     * This function compares the current complex number with another complex number and returns true if the current complex number is greater than the other complex number.
     * 
     * @param other The complex number to compare with.
     * @return True if the current complex number is greater than the other complex number, false otherwise.
     */
    bool operator>(const Complex& other) const {
        return !(*this < other) && !(*this == other);
    }

    // Convert to string for easy display
    /**
     * Returns a string representation of the complex number.
     *
     * The string representation is in the format "(real, imag)", where 'real' is the real part
     * of the complex number and 'imag' is the imaginary part of the complex number.
     *
     * @return A string representation of the complex number.
     */
    std::string toString() const {
        return "(" + std::to_string(real) + ", " + std::to_string(imag) + ")";
    }

    // Overload the << operator for easy printing
    /**
     * Overloads the << operator to allow printing a Complex object.
     *
     * @param os The output stream to write to.
     * @param c The Complex object to be printed.
     * @return The output stream after writing the Complex object.
     */
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << "(" << c.real << ", " << c.imag << ")";
        return os;
    }
};

#endif // COMPLEX_HPP

#endif // COMPLEX_HPP



