#include <stdio.h>
#ifndef DRUGS
#define DRUGS

class Drugs
{
protected:
	const char* Name;
	const char* Methods_of_consumption[3];
	int Count_methods_of_consumption;
	int Price;
	int Duration;
	int Grade_Fun;
	int Grade_Safety;
	bool Status;///if it`s legal
	//int Current;
public:
	virtual void Get_Name() = 0;
	virtual void Get_Method(int index) = 0;
	virtual int Get_Count_methods_of_consumption() = 0;
	virtual void Show_All_methods() = 0;
	virtual int Get_Price(int quantity) = 0;
	virtual int Get_Duration() = 0;
	virtual int Get_Grade_Fun() = 0;
	virtual int Get_Grade_Safety() = 0;
	virtual bool Get_Status() = 0;
};
#endif // !DRUGS
