#include "Complex.h"
#include <iostream>
#include <math.h>

using namespace std;

Complex::Complex(int real, int imaginary)
{
	this->real = real;
	this->imaginary = imaginary;
}

void Complex::Print_Short()
{
	char sign;
	imaginary < 0 ? sign = '-' : sign = '+';
	cout << real << " " << sign << " " << imaginary << "i";
}


void Complex::Print_Full()
{
	char sign;
	imaginary < 0 ? sign = '-' : sign = '+';
	cout << real << " " << sign << " " << imaginary << "i, " << Value();
}

I_Managable* Complex::Copy()
{
	Complex* new_object = new Complex(real, imaginary);
	return new_object;
}

bool Complex::is_Equal(I_Managable* object)
{
	return Value() < object->Value();
}

float Complex::Value()
{
	return sqrt(real * real + imaginary * imaginary);
}
