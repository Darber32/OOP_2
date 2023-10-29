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

void Vector_2_D::Copy(I_Copyable* object)
{
	Vector_2_D* new_object = (Vector_2_D*)object;
	new_object->x1 = x1;
	new_object->x2 = x2;
	new_object->y1 = y1;
	new_object->y2 = y2;
}

bool Vector_2_D::is_Equal(I_Managable* object)
{
	return Value() == object->Value();
}

float Vector_2_D::Value()
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}



