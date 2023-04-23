#include "Meth.h"

Meth::Meth()
{
	Name = "Meth";
	Methods_of_consumption[0] = "Pipe";
	Methods_of_consumption[1] = "Needle";
	Count_methods_of_consumption = 2;
	Price = 4;
	Duration = 15;
	Grade_Fun = 8;
	Grade_Safety = 3;
	Status = false;
}
Meth::~Meth(){}
void Meth::Get_Name()
{
	printf("%s\n", Name);
}
void Meth::Get_Method(int index)
{
	if (index - 1 < Count_methods_of_consumption)
		printf("%s\n", Methods_of_consumption[index - 1]);
}
int Meth::Get_Count_methods_of_consumption()
{
	return Count_methods_of_consumption;
}
void Meth::Show_All_methods()
{
	for (int index = 1; index <= Count_methods_of_consumption; index++)
		printf("%s\n", Methods_of_consumption[index - 1]);
}
int Meth::Get_Price(int quantity)
{
	return quantity * Price;
}
int Meth::Get_Duration()
{
	return Duration;
}
int Meth::Get_Grade_Fun()
{
	return Grade_Fun;
}
int Meth::Get_Grade_Safety()
{
	return Grade_Safety;
}
bool Meth::Get_Status()
{
	return Status;
}