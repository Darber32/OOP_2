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

void Append(I_Managable** mass, int& size, int type)
{
	char text[100] = { NULL };
	int data_mass[6] = { 0 };
	switch (type)
	{
	case 1:
		cout << "Введите нужный текст: ";
		cin.getline(text, 100);
		mass[size] = new Text(text);
		break;
	case 2:
		type = 1;
		for (int i = 0; i < 4; i++)
		{
			cout << "Введите " << type << " координату: ";
			cin >> data_mass[i];
			type++;
		}
		mass[size] = new Vector_2_D(data_mass[0], data_mass[1], data_mass[2], data_mass[3]);
		break;
	case 3:
		type = 1;
		for (int i = 0; i < 6; i++)
		{
			cout << "Введите " << type << " координату: ";
			cin >> data_mass[i];
			type++;
		}
		mass[size] = new Vector_3_D(data_mass[0], data_mass[1], data_mass[2], data_mass[3], data_mass[4], data_mass[5]);
		break;
	case 4:
		type = 1;
		for (int i = 0; i < 2; i++)
		{
			cout << "Введите " << type << " координату: ";
			cin >> data_mass[i];
			type++;
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
		bool is_sorted = false;
		while (!is_sorted)
		{
			is_sorted = true;
			for (int i = 1; i < size; i++)
			{
				if (not mass[i]->is_Equal(mass[i-1]))
				{
					temp = mass[i];
					mass[i] = mass[i - 1];
					mass[i - 1] = temp;
					is_sorted = false;
				}
			}
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
	max_el->Print_Full();
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
	min_el->Print_Full();
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
			mass[i]->Print_Full();
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
			if ((mass[i]->Value() > mass[i - 1]->Value() and mass[i]->Value() > mass[i + 1]->Value()) or 
				(mass[i]->Value() < mass[i - 1]->Value() and mass[i]->Value() < mass[i + 1]->Value()))
			{
				mass[i]->Print_Full();
				cout << endl;
			}
	}
}

void Make_Copy(I_Managable** mass, int size, I_Managable ** new_mass, int &second_size)
{
	if (second_size != 0)
	{
		for (int i = 0; i < second_size; i++)
			delete new_mass[i];
	}
	second_size = 0;
	for (int i = 0; i < size; i++)
		new_mass[second_size++] = mass[i]->Copy();
}

void Join(I_Managable** mass, int &size, I_Managable** second_mass, int second_size)
{

	for (int i = 0; i < second_size; i++)
		mass[size++] = second_mass[i]->Copy();
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
	I_Managable* text_mass[MASS_SIZE] = { nullptr }, * new_text_mass[MASS_SIZE] = { nullptr }, * vector_2_d_mass[MASS_SIZE] = { nullptr }, * vector_3_d_mass[MASS_SIZE] = { nullptr }, * complex_mass[MASS_SIZE] = {nullptr};
	int text_size = 0, text_size_2 = 0, vector_2_size = 0, vector_3_size = 0, complex_size = 0, key, type;
	bool flag = true;
	while (flag)
	{
		do
		{
			cout << "С каким массивом работать?" << endl << "1 - Текст" << endl << "2 - Двухмерный вектор" << endl << "3 - Трехмерный вектор" << endl << "4 - Комплексное число" << endl << "5 - Закончить работу" << endl;
			cin >> type;
		} while (type < 1 or type > 5);
		if (type == 5)
		{
			for (int i = 0; i < MASS_SIZE; i++)
			{
				if (text_mass[i] != nullptr)
					delete text_mass[i];
				if (new_text_mass[i] != nullptr)
					delete new_text_mass[i];
				if (vector_2_d_mass[i] != nullptr)
					delete vector_2_d_mass[i];
				if (vector_3_d_mass[i] != nullptr)
					delete vector_3_d_mass[i];
				if (complex_mass[i] != nullptr)
					delete complex_mass[i];
			}
			flag = false;
		}
		if (flag)
		{
			do
			{
				cout << "1 - Добавить элемент" << endl << "2 - Отсортировать массив" << endl << "3 - Вывести массив в краткой форме" << endl << "4 - Вывести массив в полной форме" << endl
					<< "5 - Вывести максимальный элемент" << endl << "6 - Вывести минимальный элемент" << endl << "7 - Найти элемент в списке (по значению)" << endl
					<< "8 - Вывести сумму всех элементов" << endl << "9 - Показать все элементы, значение которых находится в заданном диапазоне" << endl << "10 - Вывести пиковые значения" << endl
					<< "11 - Сделать копию массива" << endl << "12 - Соединить 2 массива" << endl << "13 - Вывести уникальные элементы" << endl;
				cin >> key;
			} while (key < 1 or key > 13);
			switch (key)
			{
			case 1:
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				switch (type)
				{
				case 1:
					Append(text_mass, text_size, type);
					break;
				case 2:
					Append(vector_2_d_mass, vector_2_size, type);
					break;
				case 3:
					Append(vector_3_d_mass, vector_3_size, type);
					break;
				case 4:
					Append(complex_mass, complex_size, type);
					break;
				}
				break;
			case 2:
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				switch (type)
				{
				case 1:
					Sort(text_mass, text_size);
					break;
				case 2:
					Sort(vector_2_d_mass, vector_2_size);
					break;
				case 3:
					Sort(vector_3_d_mass, vector_3_size);
					break;
				case 4:
					Sort(complex_mass, complex_size);
					break;
				}
				break;
			case 3:
				switch (type)
				{
				case 1:
					Print_Line(text_mass, text_size);
					break;
				case 2:
					Print_Line(vector_2_d_mass, vector_2_size);
					break;
				case 3:
					Print_Line(vector_3_d_mass, vector_3_size);
					break;
				case 4:
					Print_Line(complex_mass, complex_size);
					break;
				}
				break;
			case 4:
				switch (type)
				{
				case 1:
					Print_Column(text_mass, text_size);
					break;
				case 2:
					Print_Column(vector_2_d_mass, vector_2_size);
					break;
				case 3:
					Print_Column(vector_3_d_mass, vector_3_size);
					break;
				case 4:
					Print_Column(complex_mass, complex_size);
					break;
				}
				break;
			case 5:
				switch (type)
				{
				case 1:
					Max(text_mass, text_size);
					break;
				case 2:
					Max(vector_2_d_mass, vector_2_size);
					break;
				case 3:
					Max(vector_3_d_mass, vector_3_size);
					break;
				case 4:
					Max(complex_mass, complex_size);
					break;
				}
				break;
			case 6:
				switch (type)
				{
				case 1:
					Min(text_mass, text_size);
					break;
				case 2:
					Min(vector_2_d_mass, vector_2_size);
					break;
				case 3:
					Min(vector_3_d_mass, vector_3_size);
					break;
				case 4:
					Min(complex_mass, complex_size);
					break;
				}
				break;
			case 7:
				switch (type)
				{
				case 1:
					cout << Find(text_mass, text_size) << endl;
					break;
				case 2:
					cout << Find(vector_2_d_mass, vector_2_size) << endl;
					break;
				case 3:
					cout << Find(vector_3_d_mass, vector_3_size) << endl;
					break;
				case 4:
					cout << Find(complex_mass, complex_size) << endl;
					break;
				}
				break;

			case 8:
				switch (type)
				{
				case 1:
					cout << Sum(text_mass, text_size) << endl;
					break;
				case 2:
					cout << Sum(vector_2_d_mass, vector_2_size) << endl;
					break;
				case 3:
					cout << Sum(vector_3_d_mass, vector_3_size) << endl;
					break;
				case 4:
					cout << Sum(complex_mass, complex_size) << endl;
					break;
				}
				break;
			case 9:
				switch (type)
				{
				case 1:
					Count_In_Range(text_mass, text_size);
					break;
				case 2:
					Count_In_Range(vector_2_d_mass, vector_2_size);
					break;
				case 3:
					Count_In_Range(vector_3_d_mass, vector_3_size);
					break;
				case 4:
					Count_In_Range(complex_mass, complex_size);
					break;
				}
				break;
			case 10:
				switch (type)
				{
				case 1:
					Print_Pikes(text_mass, text_size);
					break;
				case 2:
					Print_Pikes(vector_2_d_mass, vector_2_size);
					break;
				case 3:
					Print_Pikes(vector_3_d_mass, vector_3_size);
					break;
				case 4:
					Print_Pikes(complex_mass, complex_size);
					break;
				}
				break;
			case 11:
				Make_Copy(text_mass, text_size, new_text_mass, text_size_2);
				break;
			case 12:
				Join(text_mass, text_size, new_text_mass, text_size_2);
				break;
			case 13:
				switch (type)
				{
				case 1:
					Print_Unique(text_mass, text_size);
					break;
				case 2:
					Print_Unique(vector_2_d_mass, vector_2_size);
					break;
				case 3:
					Print_Unique(vector_3_d_mass, vector_3_size);
					break;
				case 4:
					Print_Unique(complex_mass, complex_size);
					break;
				}
				break;
			}
		}
	}
	return 0;
}

