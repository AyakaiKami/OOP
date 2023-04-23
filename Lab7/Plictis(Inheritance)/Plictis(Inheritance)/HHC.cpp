#include "HHC.h"

HHC::HHC()
{
	Name = "HHC";
	Methods_of_consumption[0] = "Vapes";
	Count_methods_of_consumption = 1;
	Price = 10;
	Duration = 3*60;
	Grade_Fun = 7;
	Grade_Safety = 8;
	Status = true;
}
HHC::~HHC(){}
void HHC::Get_Name()
{
	printf("%s\n", Name);
}
void HHC::Get_Method(int index) 
{
	if (index - 1 < Count_methods_of_consumption)
		printf("%s\n", Methods_of_consumption[index - 1]);
}
int HHC::Get_Count_methods_of_consumption()
{
	return Count_methods_of_consumption;
}
void HHC::Show_All_methods()
{
	for (int index=1;index<=Count_methods_of_consumption;index++)
		printf("%s\n", Methods_of_consumption[index - 1]);
}
int HHC::Get_Price(int quantity)
{
	return quantity * Price;
}
int HHC::Get_Duration()
{
	return Duration;
}
int HHC::Get_Grade_Fun()
{
	return Grade_Fun;
}
int HHC::Get_Grade_Safety()
{
	return Grade_Safety;
}
bool HHC::Get_Status()
{
	return Status;
}