#ifndef AI
#define AI
template<class T>
class ArrayIterator
{
private:
	int Curent;
public:
	ArrayIterator();
	ArrayIterator& operator ++ ();
	ArrayIterator& operator -- ();
	bool operator = (ArrayIterator<T>&);
	bool operator != (ArrayIterator<T>&);
	T* GetElement();
};
#endif // !AI
