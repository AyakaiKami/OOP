#ifndef NUMBERH
#define NUMBERH
#include <iostream>
class Number
{
	int base_nr;
	int *value_nr_int;
public:
	Number(const char* value, int base=10);///where base is between 2 and 16
	Number (int nr);
	Number();
	~Number();

	void SetValue(int newValue[]);
	void SetBase(int newBase);
	friend Number operator+(Number obj1,Number obj2);
	friend Number operator-(Number obj1, Number obj2);
	int operator>(Number obj2);
	int operator>=(Number obj2);
	int operator<(Number obj2);
	int operator<=(Number obj2);
	int operator==(Number obj2);
	void operator+=(Number obj2);
	int operator[](int index);
	void operator--();
	void operator--(int);
	void operator=(int nr);
	void operator=(const char* s);
	void operator=(Number obj2);
	void Print();
	int GetDigitsCount();
	int GetBase();
	void SwitchBase(int newBase);
};
#endif // !NUMBERH
