#include "Array.h"

template<class T>
Array<T>::Array() 
{
	this->Capacity = 0;
	this->Size = 0;
	this->List = nullptr;
}

template<class T>
Array<T>::~Array() { this->List = nullptr; }

template<class T>
Array<T>::Array(int capacity) 
{
	this->Capacity = capacity;
	this->Size = 0;
	this->List = new const T*[Capacity];
}

template<class T>
Array<T>::Array(const Array<T>& otherArray)
{
	this->Capacity = otherArray.Capacity;
	this->Size = otherArray.Size;
	this->List = new T[Capacity];
	for (int i = 0; i < this->Size; i++)
		this->List[i] = otherArray.List[i];
}

template<class T>
T& Array<T>::operator[](int index)
{
	if (this->index <= this->Size)
		return this->List[index];
	else
	{
		Exceptions exp;
		exp.Exception1();
	}
}

template <class T>
const Array<T>& Array<T>::operator+=(const T& newElem) 
{
	if (this->Capacity > this->Size + 1)
	{
		Exceptions exp;
		exp.Exception1();
	}
	else
	{
		this->Size++;
		this->List[this->Size - 1] = newElem;
	}
	return this;
}
template<class T>
const Array<T>& Array<T>::Insert(int index, const T& newElem)
{
	if (this->Capacity > this->Size + 1)
	{
		Exceptions exp;
		exp.Exception1();
	}
	else
	{
		this->Size++;
			for (int i = this->Size; i > index; i--)
				this->List[i] = this->List[i - 1];
		this->List[index] = &newElem;
	}
	return  *(this);
}

template <class T>
const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray)
{
	if (this->Capacity > this->Size + 1)
	{
		Exceptions exp;
		exp.Exception1();
	}
	else
	{
		this->Size++;
			for (int i = this->Size; i > index; i--)
				this->List[i] = this->List[i - 1];
		this->List[index] = &otherArray;
	}
	return this;
}
template <class T>
const Array<T>& Array<T>::Delete(int index)
{

	if (this->Capacity > this->Size + 1)
	{
		Exceptions exp;
		exp.Exception1();
	}
	else
	{
			for (int i = index; i < this->Size; i++)
				this->List[i] = this->List[i + 1];
			this->Size--;
	}
	return this;
}

template <class T>
bool Array<T>::operator==(const Array<T>& otherArray)
{
	if (this->Size != otherArray.Size)
		return false;
	else
	{
		for (int i = 0; i < this->Size; i++)
			if (this->List[i] != otherArray.List[i])
				return false;
		return true;
	}
}

template <class T>
void Array<T>::Sort()
{
	bool sorted = false;
	while (sorted)
	{
		sorted = true;
		for(int i=0;i<this->Size-1;i++)
			if (this->List[i] > this->List[i + 1])
			{
				sorted = false;
				T* cop=this->List[i];
				this->List[i] = this->List[i + 1];
				this->List[i + 1] = cop;
			}
	}
}

template <class T>
void Array<T>::Sort(int(*compare)(const T&, const T&))
{
	bool sorted = false;
	while (sorted)
	{
		sorted = true;
		for (int i = 0; i < this->Size - 1; i++)
			if (compare(this->List[i],this->List[i+1]))
			{
				sorted = false;
				T* cop = this->List[i];
				this->List[i] = this->List[i + 1];
				this->List[i + 1] = cop;
			}
	}
}

template <class T>
void Array<T>::Sort(Compare *comparator)
{
	bool sorted = false;
	while (sorted)
	{
		sorted = true;
		for (int i = 0; i < this->Size - 1; i++)
			if (comparator->CompareElements(this->List[i], this->List[i + 1])==0)
			{
				sorted = false;
					T* cop = this->List[i];
					this->List[i] = this->List[i + 1];
					this->List[i + 1] = cop;
			}
	}
}

template <class T>
int Array<T>::BinarySearch(const T& elem)
{
	this->Sort();
	int s,  f,  m;
	s = 0;
	f = Size - 1;
	m = f / 2;
	while (s < f)
	{
		m = (s + f) / 2;
		if (this->List[m] == elem)
			return m;
		if (this->List[m] > elem)
			f = m;
		else
			s = m;
	}
	return -1;
}

template <class T>
int Array<T>::BinarySearch(const T& elem, int(*compare)(const T&, const T&))
{
	this->Sort();
	int s, f, m;
	s = 0;
	f = Size - 1;
	m = f / 2;
	while (s < f)
	{
		m = (s + f) / 2;
		if (compare(this->List[m], elem)==0)
			return m;
		if (compare(this->List[m], elem) == 1)
			f = m;
		else
			s = m;
	}
	return -1;
}

template <class T>
int Array<T>::BinarySearch(const T& elem, Compare* comparator)
{
	this->Sort();
	int s, f, m;
	s = 0;
	f = Size - 1;
	m = f / 2;
	while (s < f)
	{
		m = (s + f) / 2;
		if (comparator->CompareElements(this->List[m], elem) == 0)
			return m;
		if (comparator->CompareElements(this->List[m], elem) == 1)
			f = m;
		else
			s = m;
	}
	return -1;
}

template <class T>
int Array<T>::Find(const T& elem)
{
	for (int i = 0; i < this->size; i++)
		if (this->List[i] == elem)
			return i;
	return -1;
}

template <class T>
int Array<T>::Find(const T& elem, int(*compare)(const T&, const T&))
{
	for (int i = 0; i < this->size; i++)
		if (compare(this->List[i], elem)==0)
			return i;
	return -1;
}

template <class T>
int Array<T>::Find(const T& elem, Compare* comparator)
{
	for (int i = 0; i < this->size; i++)
		if (comparator->CompareElements(this->List[i],elem)==0)
			return i;
	return -1;
}

template <class T>
void Array<T>::Print()
{
	for (int i = 0; i < this->Size; i++)
		printf("%d", *(this->List[i]));
}