#include <iostream>
#include "NumberList.h"

void main()
{
    NumberList x;
    x.Init();
    x.Add(2);
    x.Add(3);
    x.Add(1);
    x.Sort();
    x.Print();
};