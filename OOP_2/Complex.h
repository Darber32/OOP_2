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
	void Copy(I_Copyable* object);
	bool is_Equal(I_Managable* object);
	float Value();
};

