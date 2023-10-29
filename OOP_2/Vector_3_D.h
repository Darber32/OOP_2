#pragma once
#include "I_Managable.h"

class Vector_3_D: public I_Managable
{
private:
	int x1, x2, y1, y2, z1, z2;
public:
	Vector_3_D(int x1, int y1, int z1, int x2, int y2, int z2);
	void Print_Short();
	void Print_Full();
	void Copy(I_Copyable* object);
	bool is_Equal(I_Managable* object);
	float Value();
};

