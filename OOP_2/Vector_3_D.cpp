#include "Vector_3_D.h"
#include "I_Managable.h"
#include <iostream>
#include <math.h>

using namespace std;

Vector_3_D::Vector_3_D(int x1, int y1, int z1, int x2, int y2, int z2)
{
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
	this->z1 = z1;
	this->z2 = z2;
}

void Vector_3_D::Print_Short()
{
	cout << "{" << x2 - x1 << ", " << y2 - y1 << ", " << z2 - z1 << "}";
}

void Vector_3_D::Print_Full()
{
	cout << "(" << x1 << ", " << y1 << ", " << z1 << "), (" << x2 << ", " << y2 << ", " << z2 << ")" << endl;
}

I_Managable* Vector_3_D::Copy()
{
	Vector_3_D* new_object = new Vector_3_D(x1, y1, z1, x2, y2, z2);
	return new_object;
}

bool Vector_3_D::is_Equal(I_Managable* object)
{
	return Value() < object->Value();
}

float Vector_3_D::Value()
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
}
