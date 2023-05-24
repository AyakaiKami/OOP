#include "Array.h"
#include "Array.cpp"
int main()
{
    Array<int> pula(5);
    const int i = 1;
    pula.Insert(0, i);
    pula.Print();
    return 0;
}
