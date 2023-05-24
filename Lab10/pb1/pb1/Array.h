
#ifndef ARRAY
#define ARRAY
#include <stdio.h>
#include "ArrayIterator.h"
#include "Exceptions.h"
#include "Compare.h"
template<class T>
class Array
{
private:
    const T** List;
	int Capacity;
	int Size;
public:
	Array();/// Capacity = Size = 0
	~Array();//deconstructor
	Array(int capacity);///Lista e alocata cu 'capacity element
	Array(const Array<T>& otherArray);///constructor de copiere

	T& operator[](int index);///exceptie daca index este out of range

	const Array<T>& operator+=(const T& newElem);///adauga un element la sfarsit
	///si returneaza this
	const Array<T>& Insert(int index, const T& newElem);///adauga un element pe pozitia
	///index,returneaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Insert(int index, const Array<T> otherArray);///adauga o lista pe 
	///poz index return this.Index invalid=> exceptie
	const Array<T>& Delete(int index);

	bool operator==(const Array<T>& otherArray);

	void Sort();
	void Sort(int(*compare)(const T&, const T&));
	void Sort(Compare* comparator);///sorteaza folosind un obiect de comparatie

	///functii de cautare
	int BinarySearch(const T& elem);
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&));
	int BinarySearch(const T& elem, Compare* comparator);

	int Find(const T& elem);
	int Find(const T& elem, int(*compare)(const T&, const T&));
	int Find(const T& elem, Compare* comparator);

	int GetSize();
	int GetCapacity();

	ArrayIterator<T> GetBeginIterator();
	ArrayIterator<T> GetEndIterator();

	void Print();
};

#endif // !ARRAY

