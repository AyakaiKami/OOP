#include <iostream>
#include "Junkie.h"
int main()
{
    Junkie Jake;
    Jake.Set_Name("Jake");
    Jake.Add_Drug(new Meth);
    Jake.Add_Drug(new HHC);
    Jake.Show_Drugs_Used();
    Jake.Set_Age(20);
    Jake.Show_Age();
    Jake.Legal();
    return 0;
}