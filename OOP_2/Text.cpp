#define _CRT_SECURE_NO_WARNINGS
#include "Text.h"
#include "I_Managable.h"
#include <iostream>
#include <string.h>

using namespace std;

Text::Text(char * text)
{
	strcpy(this->text, text);
}

void Text::Print_Short()
{
	int x = Value();
	if (x <= 10)
		cout << text;
	else
		cout << text[0] << text[1] << text[2] << "..." << text[x - 3] << text[x - 2] << text[x - 1];
}

void Text::Print_Full()
{
	cout << text;
}

//переделать
I_Managable* Text::Copy()
{
	Text* new_text = new Text(text);
	return new_text;
}

//переделать
bool Text::is_Equal(I_Managable * object)
{
	Text* second_text = (Text*)object;
	return strcmp(text, second_text->text) > 0;
}

float Text::Value()
{
	return strlen(text);
}

