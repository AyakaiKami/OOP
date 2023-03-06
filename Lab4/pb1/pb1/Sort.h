#ifndef SORTH
#define SORTH
#include <iostream>
#include <stdarg.h>
class Sort
{
private:
	int* v;
	int size;
public:
	Sort(int size_in, int min, int max);
	Sort(int *in=nullptr, int size_in = 0):size(size_in),v(in){}
	///Sort(int* v_in, int size_in);///ca side note , avand acelasi nr de parametri
	///nu pot sa le am pe ambele in acelasi timp
	Sort(int count, ...);
	Sort(const char* s_in);

	void InsertSort(bool ascendent = false);    
	void QuickSort(bool ascendent = false);    
	void BubbleSort(bool ascendent = false);    
	void Print();    
	int  GetElementsCount();    
	int  GetElementFromIndex(int index);
};

#endif // !SORTH

