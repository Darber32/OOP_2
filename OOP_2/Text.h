#pragma once
#include "I_Managable.h"

class Text: public I_Managable
{
protected:
	char text[100] = { 0 };
public:
	Text(char * text);
	void Print_Short();
	void Print_Full();
	I_Managable* Copy();
	bool is_Equal(I_Managable* object);
	float Value();
};
