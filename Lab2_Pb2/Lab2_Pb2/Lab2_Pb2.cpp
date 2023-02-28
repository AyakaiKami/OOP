#include <iostream>
#include "Students.h"
#include <string.h>
using namespace std;
int main()
{
    Students Leo, Patrut;
    Leo.SetName("Leon (Te pup)");
    Leo.SetGradeM(9.9);
    Leo.SetGradeE(10);
    Leo.SetGradeH(8.7);
    cout << "Notele lui "<<Leo.GetName()<<" sunt :" << " " << Leo.GetGradeM() << " " <<
        Leo.GetGradeE() << " " << Leo.GetGradeH()<<" "<<Leo.GetAverageGrade()<<endl;
    Patrut.SetName("Dbl");
    Patrut.SetGradeE(3);
    Patrut.SetGradeM(4.6);
    Patrut.SetGradeH(10);
    cout << CmpName(Leo, Patrut) << endl;
    cout << CmpGradeM(Leo, Patrut) << endl;
    cout << CmpGradeE(Leo, Patrut) << endl;
    cout << CmpGradeH(Leo, Patrut) << endl;
    cout << CmpAverageGrade(Leo, Patrut) << endl;
    Grupe A;
    A.vs[0] = Leo;
    A.vs[0] = Patrut;
    A.sortS();
    A.showG();
    return 0;
}
