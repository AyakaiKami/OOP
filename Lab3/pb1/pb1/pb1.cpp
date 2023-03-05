#include "Math.h"
#include <iostream>

int main()
{
    std::cout << Math::Add(1, 2)<<"\n";
    printf("%d \n", Math::Add(1, 2, 3));
    printf("%d \n", Math::Add(2.4, 3.3));
    printf("%d \n", Math::Add(2.4, 3.3,1.1));
    printf("%d \n", Math::Mul(2, 3));
    printf("%d \n", Math::Mul(2, 3,0));
    printf("%d \n", Math::Mul(2.3, 4.5));
    printf("%d \n", Math::Mul(2.3, 4.5,1.1));
    int v[]= { 1,2,3,4 };
    printf("%d \n", Math::Add(4, v));
    printf("% s \n", Math::Add("Giurgi", "o face okkk"));
    return 0;
}
