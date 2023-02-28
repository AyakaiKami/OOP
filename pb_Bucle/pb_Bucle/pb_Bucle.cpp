// pb_Bucle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
struct punct
{
    punct* next;
    int x, y;
};
int* more_space(int* old_ptr, int old_s, int new_s)
{
    int* new_ptr = new int[new_s];
    for (int i = 0; i < old_s; i++)
        new_ptr[i] = old_ptr[i];
    delete old_ptr;
    return new_ptr;
}
int number_loops(punct* s)
{
    int cs = 256;
    int* x = new int[cs];
    int* y = new int[cs];
    int count = 0;
    int loops = 0;
    x[count] = s->x;
    y[count++] = s->y;
    s = s->next;
    
    while (s->next != NULL)
    {
        for (int i = 0; i <count; i++)
        {
           
            if (x[i] == s->x && y[i] == s->y)
            {
                loops++;
                
                while (s != NULL && x[i] == s->x && y[i] == s->y && i < count)
                {
                    s = s->next; i++;
                }
                if (i == count || s == NULL)
                    return loops;
            }
            x[count] = s->x;
            y[count++] = s->y;
            if (count >= cs)
            {
                x = more_space(x, cs, cs + 256);
                y= more_space(y, cs, cs + 256);
                cs += 256;
            }
        }
    }
    return loops;
}
int main()
{
    punct *n1, *n2, *n3;
    n1 = new punct; n2 = new punct; n3 = new punct;
    n1->next = n2; n1->x = 1; n1->y = 1;
    n2->next = n3; n2->x = 2; n2->y = 2;
    n3->next = NULL; n3->x = 3; n3->y = 3;
    std::cout << number_loops(n1);
    return 0;
}