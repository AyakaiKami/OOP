#include "Sort.h"
#include <iostream>

int main()
{
    Sort rdm(10, 0, 55);
    rdm.Print(); printf("\n");
    rdm.BubbleSort();
    rdm.Print(); printf("\n");

    Sort cti("10,44,1,7,4,9");
    cti.InsertSort();
    cti.Print(); printf("\n");

    Sort spp(7, 8, 3, 53, 6, 3, 86, 43);
    spp.QuickSort();
    spp.Print(); printf("\n");

    int v[] = {3,7,2,9,120};
    Sort inv(v,5);
    printf("Elementul al %d -lea este %d \n", inv.GetElementsCount(),inv.GetElementFromIndex(inv.GetElementsCount()-1));
    
    return 0;
}