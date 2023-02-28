#include <iostream>
#include "NumberList.h"

int main()
{
    NumberList x;
    x.Init();
    x.Add(1);
    x.Add(0);
    x.Add(3);
    x.Sort();
    x.Print();
    return 0;
}