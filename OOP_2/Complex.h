#pragma once
#include "I_Managable.h"


class Complex: public I_Managable
{
protected:
	int real, imaginary;
public:
	Complex(int real, int imaginary);
	void Print_Short();
	void Print_Full();
	I_Managable* Copy();
	bool is_Equal(I_Managable* object);
	float Value();
};

