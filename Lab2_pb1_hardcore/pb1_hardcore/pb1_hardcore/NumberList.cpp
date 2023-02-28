#include "NumberList.h"
#include <iostream>

void NumberList::Init()
{
	count = 0;
	numbersvo = new int[256];
}
void NumberList::Add(int x)
{
	count++;
	if (count > 256)
		this->More();
	numbersvo[count-1] = x;
}
void NumberList::Sort()
{
	int c;
	bool sorto = false;
	while (sorto == false)
	{
		sorto = true;
		for (int i = 0; i < count - 1; i++)
			if (numbersvo[i] > numbersvo[i + 1])
			{
				c = numbersvo[i];
				numbersvo[i] = numbersvo[i + 1];
				numbersvo[i + 1] = c;
				sorto = false;
			}
	}
}
void NumberList::Print()
{
	for (int i = 0; i < count; i++)
		std::cout << numbersvo[i] << " ";
}

void NumberList::More()
{
	int* a = new int[this->count - 1 + 256], * y = this->numbersvo;
	for (int i = 0; i < this->count - 1; i++)
		a[i] = y[i];
	delete y;
	this->numbersvo = a;
}