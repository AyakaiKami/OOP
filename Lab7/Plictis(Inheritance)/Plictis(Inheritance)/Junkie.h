#include "HHC.h"
#include "Meth.h"
#ifndef JUNKIE
#define JUNKIE
class Junkie {
private:
	Drugs* Drugs_Used[5];
	int Size_Drugs_Used;
	const char* Name_Junkie;
	int Age;
public:
	Junkie();
	~Junkie();
	void Add_Drug(Drugs* in);
	void Set_Name(const char* in);
	void Show_Drugs_Used();
	void Set_Age(int in);
	void Show_Age();
	bool Legal();
};
#endif // !JUNKIE
