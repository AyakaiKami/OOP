#include "Junkie.h"
Junkie::Junkie() { Size_Drugs_Used = 0; }
Junkie::~Junkie(){}
void Junkie::Add_Drug(Drugs* in) 
{
	Drugs_Used[Size_Drugs_Used] = in;
	Size_Drugs_Used++;
}
void Junkie::Set_Name(const char* in)
{
	Name_Junkie = in;
}
void Junkie::Show_Drugs_Used()
{
	printf("%s uses:\n",Name_Junkie);
	for (int i = 0; i < Size_Drugs_Used; i++)
		Drugs_Used[i]->Get_Name();
}
void Junkie::Set_Age(int in)
{
	Age = in;
}
void Junkie::Show_Age()
{
	printf("%s is %d years old\n",Name_Junkie,Age);
}
bool Junkie::Legal()
{
	for (int i = 0; i < Size_Drugs_Used; i++)
		if (Drugs_Used[i]->Get_Status() == false)
		{
			printf("%s is breaking the law", Name_Junkie);
			return false;
		}
	printf("%s is not breaking any law", Name_Junkie);
	return true;
}