#include "Canvas.h"
#include <iostream>

int main()
{
    Canvas C(100, 100);
    C.DrawLine(0, 0, 19, 19, 'r');
    C.DrawLine(0, 19, 19, 0,'r');
    C.Print();
    
    C.Clear();
    C.DrawRect(0, 0, 19, 19, 'a');
    C.Print();
    C.FillRect(5, 5, 10, 10, 'a');
    C.Print();
    C.Clear();
    C.DrawCircle(3, 3,7, '4');
    C.FillCircle(87, 86, 10, '4');
    C.Print();
    
    return 0;
}