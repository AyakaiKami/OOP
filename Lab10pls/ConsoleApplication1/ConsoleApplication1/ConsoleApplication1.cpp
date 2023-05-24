#include "Array.h"


int compare(const int& x, const int& y)
{
    if (x > y)
        return 1;
    return 0;
}

int main()
{
    Array<int> A(3),B(1);
    int x = 6,y=7,z=9,m=0;
    A += x;
    B += z;
    B += m;
    A.Insert(0, y);
    A.Insert(0, B);
    A.Delete(0);

   // Cresc* cc ;
    A.Sort();
    std::cout << A.BinarySearch(0)<<"\n";
    A.Print();

    return 0;
}
