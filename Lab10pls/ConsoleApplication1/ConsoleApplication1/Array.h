#ifndef ARRAY
#define ARRAY

#include<iostream>

class Compare 
{ 
public:
	virtual int CompareElements(void* e1, void* e2) = 0; 
};

class Cresc :Compare
{
public:
	int CompareElements(void* e1, void* e2) 
	{
		if (&e1 > &e2)
			return 0;
		return 1;
	}
};

template<class T>
class ArrayIterator
{
private:
	int Curent;
public:
	ArrayIterator()
	{
		this->Curent = -1;
	}
	ArrayIterator& operator ++()
	{

	}
};




template<class T>
class Array
{
private:
	T** List;
	int Capacity;
	int Size;
public:
	Array() 
	{
		this->List = nullptr;
		this->Capacity = 0;
		this->Size = 0;
	}
	~Array()
	{
		this->List = nullptr;
		this->Capacity = 0;
		this->Size = 0;
	}
	Array(int capacity)
	{
		this->List = new  T* [capacity];
		this->Capacity = capacity;
		this->Size = 0;
	}
	Array(const Array<T>& otherArray)
	{
		this->Capacity = otherArray.Capacity;
		this->Size = otherArray.Size;
		this->List = new T* [this->Capacity];
		for (int i = 0; i < otherArray.Size; i++)
			this->List[i] = otherArray.List[i];
	}

	T& operator[](int index)
	{
		if (index >= this->Size)
			throw "Index not good";
		return this->List[index];
	}

	void Print() 
	{
		for (int i = 0; i < this->Size; i++)
			std::cout << *(this->List[i]) << " ";
		std::cout << "\n";
	}

	const Array<T>& operator += (T & newElem)
	{
		this->List[Size] = &newElem;
		this->Size++;
		return *this;
	}

	const Array<T>& Insert(int index, T& newElem)
	{
		if (index >= this->Size)
			throw "Index not good";
		for (int i = this->Size; i > index; i--)
			this->List[i] = this->List[i - 1];
		this->Size++;
		this->List[index] = &newElem;
		
		return *this;
	}

	const Array<T>& Insert(int index,const Array<T>&otherArray)
	{
		if (index >= this->Size)
			throw "Index not good";
		for (int i = otherArray.Size-1; i >= 0; i--)
			this->Insert(index, *otherArray.List[i]);
		return *this;
	}

	const Array<T>& Delete(int index) 
	{
		if (index >= this->Size)
			throw "Index not good";
		this->Size--;
		for (int i = index; i < this->Size; i++)
			this->List[i] = this->List[i + 1];
		return *this;
	}

	bool operator==(const Array<T>& otherArray)
	{
		if (this->Size != otherArray.Size)
			return 0;
		for (int i = 0; i < this->Size; i++)
			if (this->List[i] != otherArray.List[i])
				return 0;
		return 1;
	}

	void Sort()
	{
		bool sorted=false;
		while(!sorted)
		{
			sorted = true;
			for(int i=0;i<this->Size-1;i++)
				if (*(this->List[i]) > *(this->List[i + 1]))
				{
					T* cop = this->List[i];
					this->List[i] = this->List[i + 1];
					this->List[i + 1] = cop;
					sorted = false;
				}
		}
	}

	void Sort(int(*compare)(const T&, const T&))
	{
		bool sorted = false;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < this->Size - 1; i++)
				if (compare(*(this->List[i]),*(this->List[i+1])))
				{
					T* cop = this->List[i];
					this->List[i] = this->List[i + 1];
					this->List[i + 1] = cop;
					sorted = false;
				}
		}
	}

	void Sort(Compare* comparator)
	{
		bool sorted = false;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < this->Size - 1; i++)
				if (comparator->CompareElements(this->List[i], this->List[i + 1]))
				{
					T* cop = this->List[i];
					this->List[i] = this->List[i + 1];
					this->List[i + 1] = cop;
					sorted = false;
				}
		}
	}

	int BinarySearch(const T& elem)
	{
		int st = 0,dr=this->Size-1;

		while (st<dr )
		{
			int mij = (st + dr) / 2;
			if (elem > *(this->List[mij]))
				st = mij;
			if (elem < *(this->List[mij]))
				dr = mij;
			if (elem == *(this->List[mij]))
				return mij;
		}
		return -1;
	}

	int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
	{
		int st = 0, dr = this->Size - 1;

		while (st < dr)
		{
			int mij = (st + dr) / 2;
			if (compare(elem , *(this->List[mij]))==-1)
				st = mij;
			if (compare(elem, *(this->List[mij])) == 1)
				dr = mij;
			if (compare(elem, *(this->List[mij])) == 0)
				return mij;
		}
		return -1;
	}

	int BinarySearch(const T& elem, Compare *comparator)
	{
		int st = 0, dr = this->Size - 1;

		while (st < dr)
		{
			int mij = (st + dr) / 2;
			if (comparator->CompareElements(elem, *(this->List[mij])) == -1)
				st = mij;
			if (comparator->CompareElements(elem, *(this->List[mij])) == 1)
				dr = mij;
			if (comparator->CompareElements(elem, *(this->List[mij])) == 0)
				return mij;
		}
		return -1;
	}

	int Find(const T& elem)
	{
		for (int i = 0; i < this->Size; i++)
			if (elem == *(this->List[i]))
				return i;
		return -1;
	}

	int Find(const T& elem, int(*compare)(const T&, const T&))
	{
		for (int i = 0; i < this->Size; i++)
			if (compare(elem,*(this->List[i]))==1)
				return i;
		return -1;
	}
	int Find(const T& elem, Compare* comparator)
	{
		for (int i = 0; i < this->Size; i++)
			if (comparator->CompareElements(elem, *(this->List[i])) == 0)
				return i;
		return -1;
	}

	int getSize()
	{
		return this->Size;
	}

	int GetCapacity()
	{
		return this->Capacity;
	}

	ArrayIterator<T> GetBeginIterator()
	{
		return this->List[0];
	}
	ArrayIterator<T> GetEndIterator()
	{
		return this->List[this->Size-1];
	}

};
#endif // !ARRAY

