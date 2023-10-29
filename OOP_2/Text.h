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
	void Copy(I_Copyable* object);
	bool is_Equal(I_Managable* object);
	float Value();
};
