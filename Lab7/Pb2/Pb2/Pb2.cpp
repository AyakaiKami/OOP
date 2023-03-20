#include <iostream>
template <class T>
class Vect {
    T *List;
    int count;
public:
    Vect() :count(0) { List = new T[256]; }
    void Resize() 
    {
        T* newList; 
        newList = new T[sizeof(T)+256];
        for (int i = 0; i < count; i++)
            newList[i] = List[i];
        delete List;
        List = newList;
    }
    void Push(T value) { List[count++] = value; }
    T Pop() { return List[--count]; }
    void Remove(int index) {
        for (int i = index; i < count - 1; i++)
            List[i] = List[i + 1];
        count--;
    }
    void Insert(T value, int index) {
        if (count + 1 > sizeof(List))
            Resize();
        if (index <= count)
        {
            for (int i = count; i > index; i--)
                List[i] = List[i - 1];
            count++;
            List[index] = value;
        }
        else
            printf("Pozitia nu exista");
    }
    int Count() { return count; }
    void Sort(bool (*cmp)(T x,T Y)=NULL)
    {
        if (cmp != NULL)
        {
            for (int i = 0; i < count - 1; i++)
                for (int j = i+1; j < count; j++)
                    if (cmp(List[i], List[j]))
                    {
                        T cop = List[i];
                        List[i] = List[j];
                        List[j] = cop;
                    }
        }
        else
            for (int i = 0; i < count - 1; i++)
                for (int j = i+1; j < count; j++)
                    if (List[i]>List[j])
                    {
                        T cop = List[i];
                        List[i] = List[j];
                        List[j] = cop;
                    }
    }
    void Afis(void (*outp)(T x) = NULL)
    {
        if (outp != NULL)
        {
            for (int i = 0; i < count; i++)
                outp(List[i]);
        }
        else
            for (int i = 0; i < count; i++)
                printf("%d ", List[i]);
    }
    T* Get(int index) { return &List[index]; }
    void Set(int index, T* x) { List[index] = *x; }
    int firstIndexOf(T* x,bool (*equ)(T x,T y)=NULL) 
    {
        if (equ != NULL)
        {
            for (int i = 0; i < count; i++)
                if (equ(List[i], *x))
                    return i;
        }
        else
        {
            for (int i = 0; i < count; i++)
                if (List[i] == *x)
                    return i;
        }
    }
};
bool cmp(int x, int y)
{
    if (x > y)
        return true;
    else
        return false;
}
int main()
{
    Vect<int> s;
    s.Push(20); s.Push(100);
    s.Push(3); s.Push(5); s.Push(0);
    s.Insert(0, 0); s.Remove(0);
    s.Sort();
    printf("%d \n", s.Pop());
    int va = 69;
    s.Set(2, &va);
    int *x = s.Get(2); printf("%d", *x);
    printf("%d \n", s.firstIndexOf(&va));
    s.Afis();
    return 0;
}
