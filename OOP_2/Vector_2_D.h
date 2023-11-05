#pragma once
#include "I_Managable.h"

class Vector_2_D: public I_Managable
{
private:
	int x1, x2, y1, y2;
public:
	Vector_2_D(int x1, int y1, int x2, int y2);
	void Print_Short();
	void Print_Full();
	I_Managable* Copy();
	bool is_Equal(I_Managable* object);
	float Value();
};

