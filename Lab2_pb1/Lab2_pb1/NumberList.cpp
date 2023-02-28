#include "NumberList.h"
#include <iostream>
void NumberList::Init()
{
	count = 0;
};
bool NumberList::Add(int x)
{
	if (count >= 10)
		return false;
	numbers[count++] = x;
	return true;
};
void NumberList::Sort()
{
	int c;
	bool sorto=false;
	while (sorto == false)
	{
		sorto = true;
		for(int i=0;i<count-1;i++)
			if (numbers[i] > numbers[i + 1])
			{
				c = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = c;
				sorto = false;
			}
	}
}
void NumberList::Print()
{
	for (int i = 0; i < count; i++)
		std::cout << numbers[i] << " ";
};