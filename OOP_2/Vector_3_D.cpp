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

void Vector_3_D::Copy(I_Copyable* object)
{
	Vector_3_D* new_object = (Vector_3_D*)object;
	new_object->x1 = x1;
	new_object->x2 = x2;
	new_object->y1 = y1;
	new_object->y2 = y2;
	new_object->z1 = z1;
	new_object->z2 = z2;
}

bool Vector_3_D::is_Equal(I_Managable* object)
{
	return Value() == object->Value();
}

float Vector_3_D::Value()
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
}
