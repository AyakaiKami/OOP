

#include <iostream>
#include <algorithm>

#include <vector>
using namespace std;
template<class T>
class LISTA
{
private:
    T* LIST;
    int size;
    int capacitate;
public:
    LISTA() {
        LIST = nullptr;
        size = 0;
        capacitate = 0;
    }
    ~LISTA()
    {
        delete[] LIST;
    }
    LISTA(int capacitate)
    {
        LIST = new T[capacitate];
        this->capacitate = capacitate;
        size = 0;
    }
    T& operator[](int index)
    {

        return LIST[index];
    }
    const LISTA<T>& Insert(int index, const T& newElem)
    {
        if (size == capacitate)
        {
            T* newList = new T[size + 1];
            for (int i = 0; i < index; i++)
                newList[i] = LIST[i];

            newList[index] = newElem;
            for (int i = index + 1; i <=size; i++)
                newList[i] = LIST[i - 1];
            delete[] LIST;
            LIST = newList;
            capacitate++;
            size++;
        }
        else
        {
            for (int i = size; i >index; i--)
                LIST[i] = LIST[i - 1];
            LIST[index] = newElem;
            size++;
        }
        return *this;
    }



    void Sort()
    {
        int i, j, min_idx;
        for (i = 0; i < size; i++)
        {
            min_idx = i;
            for (j = i; j < size; j++)
            {

                if (LIST[j] < LIST[min_idx])
                    min_idx = j;
            }
            if (min_idx != i)
            {

                T aux = LIST[i];
                LIST[i] = LIST[min_idx];
                LIST[min_idx] = aux;
            }
        }

    }
    int GetSize()
    {
        return size;
    }
};

int main()
{
    LISTA<int> a(10);
    a.Insert(0, 3);
    a.Insert(1, 5);
    a.Insert(2, 2);
    a.Sort();
    for (int i = 0; i < a.GetSize(); i++)
        cout << a[i] << " ";
    return 0;
}


