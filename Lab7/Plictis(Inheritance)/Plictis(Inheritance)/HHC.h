#include "Drugs.h"
#ifndef HHC
#define HHC_V
class HHC:public Drugs{
private:
	const char* Name;
	const char* Methods_of_consumption[3];
	int Count_methods_of_consumption;
	int Price;
	int Duration;
	int Grade_Fun;
	int Grade_Safety;
	bool Status;///if it`s legal
public:
	HHC();
	~HHC();
	void Get_Name() override;
	void Get_Method(int index) override;
	int Get_Count_methods_of_consumption() override;
	void Show_All_methods() override;
	int Get_Price(int quantity) override;
	int Get_Duration() override;
	int Get_Grade_Fun() override;
	int Get_Grade_Safety()override;
	bool Get_Status()override;
};
#endif // !HHC
