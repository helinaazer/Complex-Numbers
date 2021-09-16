#include <iostream>
#include <cmath>
#include "complex.h"

using namespace std;

//------------------Stream I/O -----------------------
//function that controls how things display on the screen
ostream& operator << (ostream& out, const complex& r) {

    if (r.real == 0 && r.imaginary == 0)
    {
        out << 0;
    }
    else if (r.real != 0)
    {
        out << r.real;
        if (r.imaginary != 0)
        {
            if (r.imaginary == 1)
            {
                out << " + i";
            }
            else if (r.imaginary == -1)
            {
                out << " - i";
            }
            else if (r.imaginary > 0)
            {
                out << " + " << r.imaginary << "i";
            }
            else if (r.imaginary < 0)
            {
                out << " - " << -r.imaginary << "i";
            }
        }
    }
    else
    {
        if (r.imaginary != 0)
        {
            if (r.imaginary == 1)
            {
                out << "i";
            }
            else if (r.imaginary == -1)
            {
                out << "-i";
            }
            else if (r.imaginary > 1)
            {
                out << r.imaginary << "i";
            }
            else if (r.imaginary < -1)
            {
                out << "-" << -r.imaginary << "i";
            }
        }
    }

    return out;
}

//function that reads input from the user
istream& operator >> (istream& in, complex& r) {
    in >> r.real >> r.imaginary;
    return in;
}

//-------------Constructors---------------

//constructor with two arguments
complex::complex(double x, double y) {
    real = x;
    imaginary = y;
}

//-----------Member Functions ---------------

//set method for the real number. Sets the real part of the complex number
void complex::setReal(double x) {
    real = x;
}

//set method for the imaginary number. Sets the imaginary part of the complex number
void complex::setImaginary(double y) {
    imaginary = y;
}

//get method for the real number. Returns the real part of the complex number.
double complex::getReal() {
    return real;
}

//get method for the imaginary number. Returns the imaginary part of the complex number.
double complex::getImaginary() {
    return imaginary;
}

//---------------------Math Operators-------------------

//--------------Addition--------------------
//add method to add complex numbers
complex complex::operator+(const complex& c) {
    return complex((*this).real + c.real, (*this).imaginary + c.imaginary);
}
//--------------Subtraction--------------------
//subtract method to subtract complex numbers
complex complex::operator-(const complex& c) {
    return complex((*this).real - c.real, (*this).imaginary - c.imaginary);
}
// //--------------Multiplication--------------------
//multiplication method to multiply complex numbers
complex complex::operator*(const complex& c) {
    return complex(((*this).real * c.real) + ((*this).imaginary * c.imaginary * -1), ((*this).real * c.imaginary) + (c.real * (*this).imaginary));
}
//--------------Division--------------------
//division method to divide complex numbers
complex complex:: operator/(const complex& c) {
    complex temp = c;
    complex numerator = *this * temp.conjugate();
    complex denominator = temp * temp.conjugate();
    if (denominator.real == 0) {
      cout << "Undefined, cannot divide by zero: ";
      return *this;
    }
    return complex(numerator.real / denominator.real, numerator.imaginary / denominator.real);
}
//-----------------Conjugate------------------
//conjugate method that changes the sign (+ to - or - to +)
complex complex::conjugate() {
    return complex((*this).real, -imaginary);
}

//----------------Comparison-------------------
//method checks if two complex numbers are equal. Returns true if equal, returns false if not equal.
bool complex:: operator==(const complex& c) const {
    return ((*this).real == c.real && (*this).imaginary == c.imaginary);
}
//method that checks if two complex numbers are not equal. Returns true if not equal, returns false if equal.
bool complex::operator!=(const complex& c) const {
    return !(*this == c);
}

//----------------Assignment--------------------
//method that adds two complex numbers and reassigns its value.
complex& complex::operator+=(const complex& c) {
    (*this).real += c.real;
    (*this).imaginary += c.imaginary;
    return *this;
}

//method that subtracts two complex numbers and reassigns its value.
complex& complex::operator-=(const complex& c) {
    (*this).real -= c.real;
    (*this).imaginary -= c.imaginary;
    return *this;
}

//method that multiplies two complex numbers and reassigns its value.
complex& complex::operator*=(const complex& c) {
    *this = *this * c;
    return *this;
}

//method that divides two complex numbers and reassigns its value.
complex& complex::operator/=(const complex& c) {
    *this = *this / c;
    return *this;
}