#define _CRT_SECURE_NO_WARNINGS
#define MASS_SIZE 100
#include <iostream>
#include <string.h>
#include "I_Printable.h"
#include "I_Copyable.h"
#include "I_Value.h"
#include "I_Managable.h"
#include "Text.h"
#include "Vector_2_D.h"
#include "Vector_3_D.h"
#include "Complex.h"

using namespace std;

void Append(I_Managable** mass, int& size)
{
	char text[100] = { NULL };
	int key;
	int data_mass[6] = { 0 };
	do
	{
		cout << "Какой элемент хотите создать?" << endl << "1 - Текст" << endl << "2 - Двухмерный вектор" << endl << "3 - Трехмерный вектор" << endl << "4 - Комплексное число" << endl;
		cin >> key;
	} while (key < 1 or key > 4);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	switch (key)
	{
	case 1:
		cout << "Введите нужный текст: ";

		cin.getline(text, 100);
		mass[size] = new Text(text);
		break;
	case 2:
		key = 1;
		for (int i = 0; i < 4; i++)
		{
			cout << "Введите " << key << " координату: ";
			cin >> data_mass[i];
			key++;
		}
		mass[size] = new Vector_2_D(data_mass[0], data_mass[1], data_mass[2], data_mass[3]);
		break;
	case 3:
		key = 1;
		for (int i = 0; i < 6; i++)
		{
			cout << "Введите " << key << " координату: ";
			cin >> data_mass[i];
			key++;
		}
		mass[size] = new Vector_3_D(data_mass[0], data_mass[1], data_mass[2], data_mass[3], data_mass[4], data_mass[5]);
		break;
	case 4:
		key = 1;
		for (int i = 0; i < 2; i++)
		{
			cout << "Введите " << key << " координату: ";
			cin >> data_mass[i];
			key++;
		}
		mass[size] = new Complex(data_mass[0], data_mass[1]);
		break;
	}
	size++;
}

void Sort(I_Managable** mass, int size)
{
	if (size != 0)
	{
		I_Managable* temp;
		int c = 0;
		bool flag = true;
		while (flag)
		{
			for (int i = 1; i < size; i++)
			{
				if (mass[i]->Value() > mass[i - 1]->Value())
				{
					temp = mass[i];
					mass[i] = mass[i - 1];
					mass[i - 1] = temp;
					c++;
				}
			}
			if (c == 0)
				flag = false;
			c = 0;
		}
	}
}

void Print_Line(I_Managable** mass, int size)
{
	for (int i = 0; i < size; i++)
	{
		mass[i]->Print_Short();
		if (i != size - 1)
			cout << ", ";
	}
	cout << endl;
}

void Print_Column(I_Managable** mass, int size)
{
	for (int i = 0; i < size; i++)
	{
		mass[i]->Print_Full();
		cout << endl;
	}
}

void Max(I_Managable** mass, int size)
{
	float max = INT_MIN;
	I_Managable* max_el = nullptr;
	for (int i = 0; i < size; i++)
		if (max < mass[i]->Value())
		{
			max = mass[i]->Value();
			max_el = mass[i];
		}
	cout << "Максимальный элемент: ";
	max_el->Print_Short();
	cout << ". Значение максимального элемента: " << max << endl;

}

void Min(I_Managable** mass, int size)
{
	float min = INT_MAX;
	I_Managable* min_el = nullptr;
	for (int i = 0; i < size; i++)
		if (min > mass[i]->Value())
		{
			min = mass[i]->Value();
			min_el = mass[i];
		}
	cout << "Минимальный элемент: ";
	min_el->Print_Short();
	cout << ". Значение минимального элемента: " << min << endl;
}

int Find(I_Managable** mass, int size)
{
	float data;
	cout << "Введите значение элемента: ";
	cin >> data;
	for (int i = 0; i < size; i++)
		if (mass[i]->Value() == data)
			return i;
	return INT_MIN;
}

float Sum(I_Managable** mass, int size)
{
	float sum = 0;
	for (int i = 0; i < size; i++)
		sum += mass[i]->Value();
	return sum;
}

int Count_In_Range(I_Managable** mass, int size)
{
	int a, b, c = 0;
	cout << "Введите начальное значение: ";
	cin >> a;
	cout << "Введите конечное значение: ";
	cin >> b;
	for (int i = 0; i < size; i++)
		if (mass[i]->Value() >= a and mass[i]->Value() <= b)
		{
			mass[i]->Print_Short();
			cout << endl;
			c++;
		}
	return c;
}

void Print_Pikes(I_Managable** mass, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			if (mass[i]->Value() > mass[i + 1]->Value() or mass[i]->Value() < mass[i + 1]->Value())
			{
				mass[i]->Print_Full();
				cout << endl;
			}
		}
		else if (i == size - 1)
		{
			if (mass[i]->Value() > mass[i - 1]->Value() or mass[i]->Value() < mass[i - 1]->Value())
			{
				mass[i]->Print_Full();
				cout << endl;
			}
		}
		else
			if ((mass[i]->Value() > mass[i - 1]->Value() and mass[i]->Value() > mass[i + 1]->Value()) or (mass[i]->Value() < mass[i - 1]->Value() and mass[i]->Value() < mass[i + 1]->Value()))
			{
				mass[i]->Print_Full();
				cout << endl;
			}
	}
}

void Make_Copy(I_Managable** mass, int size, I_Managable ** new_mass)
{
}

void Join(I_Managable** mass, int size, I_Managable** second_mass, int second_size)
{
}

void Print_Unique(I_Managable** mass, int size)
{
	int c = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			if (i != j and mass[i]->Value() == mass[j]->Value())
				c++;
		if (c == 0)
		{
			mass[i]->Print_Full();
			cout << endl;
		}
		else
			c = 0;
	}
}

int main()
{
	system("chcp 1251 > null");
	I_Managable* mass[MASS_SIZE] = { nullptr }, *new_mass[MASS_SIZE] = {nullptr};
	int count = 0, key;
	bool flag = true;
	while (flag)
	{
		do
		{
			cout << "1 - Добавить элемент" << endl << "2 - Отсортировать массив" << endl << "3 - Вывести массив в краткой форме" << endl << "4 - Вывести массив в полной форме" << endl
				<< "5 - Вывести максимальный элемент" << endl << "6 - Вывести минимальный элемент" << endl << "7 - Найти элемент в списке (по значению)" << endl 
				<<  "8 - Вывести сумму всех элементов" << endl << "9 - Показать все элементы, значение которых находится в заданном диапазоне" << endl << "10 - Вывести пиковые значения" << endl 
				<< "11 - Сделать копию массива" << endl << "12 - Соединить 2 массива" << endl << "13 - Вывести уникальные элементы" << endl << "14 - Закончить работу" << endl;
			cin >> key;
		} while (key < 1 or key > 14);
		switch (key)
		{
		case 1:
			Append(mass, count);
			break;
		case 2:
			Sort(mass, count);
			break;
		case 3:
			Print_Line(mass, count);
			break;
		case 4:
			Print_Column(mass, count);
			break;
		case 5:
			Max(mass, count);
			break;
		case 6:
			Min(mass, count);
			break;
		case 7:
			cout << Find(mass, count) << endl;
			break;
		case 8:
			cout << Sum(mass, count) << endl;
			break;
		case 9:
			Count_In_Range(mass, count);
			break;
		case 10:
			Print_Pikes(mass, count);
			break;
		case 13:
			Print_Unique(mass, count);
			break;
		case 14:
			for (int i = 0; i < 30; i++)
				if (mass[i] != nullptr)
					delete mass[i];
			flag = false;
		}
	}
	return 0;
}

