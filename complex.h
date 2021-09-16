#include <iostream>

#ifndef COMPLEX_H
#define COMPLEX_H
using namespace std;

class complex {
	friend ostream& operator<< (ostream&, const complex&); //displays output on screen
	friend istream& operator>>(istream& in, complex&); //reads input from user
public:

	complex(double x = 0, double y = 0); //constructor
	double getReal(); //method that gets the value of real
	double getImaginary(); // method that gets the value of imaginary
	void setReal(double x); //sets the value of real
	void setImaginary(double y); //sets the value of imaginary
	complex operator+(const complex& c); //adds complex numbers
	complex operator-(const complex& c); // susbtracts complex numbers
	complex conjugate(); //changes the sign of the complex number
	complex operator*(const complex& c); //multiplies complex numbers
	complex operator/(const complex& c); //divides complex numbers
	bool operator==(const complex&) const; //is complex number equal to parameter
	bool operator!=(const complex&) const; //is complex number not equal to parameter
	complex& operator+=(const complex&); //complex number plus equal parameter
	complex& operator-=(const complex&); //complex number minus equal parameter
	complex& operator*=(const complex& c); //complex number times equal parameter
	complex& operator/=(const complex& c); //complex number divide equal parameter
private:
	float real; 
	float imaginary;

};

#endif