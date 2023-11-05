#include "Vector_2_D.h"
#include "I_Managable.h"
#include <iostream>
#include <math.h>

using namespace std;

Vector_2_D::Vector_2_D(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
}

void Vector_2_D::Print_Short()
{
	cout << "{" << x2 - x1 << ", " << y2 - y1 << "}";
}

void Vector_2_D::Print_Full()
{
	cout << "(" << x1 << ", " << y1 << "), (" << x2<< ", " << y2 << ")";
}

I_Managable* Vector_2_D::Copy()
{
	Vector_2_D* new_object = new Vector_2_D(x1, y1, x2, y2);
	return new_object;
}

bool Vector_2_D::is_Equal(I_Managable* object)
{
	return Value() < object->Value();
}

float Vector_2_D::Value()
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}



