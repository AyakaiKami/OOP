#include "Students.h"
#include <iostream>
#include <string.h>
void Students::SetName( const char* x)
{
	Names = x;
};
const char* Students::GetName()
{
	return Names;
}
void Students::SetGradeM(float x)
{
	GradeM = x;
};
void Students::SetGradeE(float x)
{
	GradeE = x;
};
void Students::SetGradeH(float x)
{
	GradeH = x;
};
float Students::GetGradeM()
{
	return GradeM;
};
float Students::GetGradeE()
{
	return GradeE;
};
float Students::GetGradeH()
{
	return GradeH;
};
float Students::GetAverageGrade()
{
	float AG = this->GetGradeM() + this->GetGradeE() + this->GetGradeH();
	AG = AG / 3;
	return AG;
};

void Grupe::sortS()
{
		Students c;
		bool sorto = false;
		while (sorto == false)
		{
			sorto = true;
			for (int i = 0; i < n - 1; i++)
				if (vs[i].GetAverageGrade() > vs[i].GetAverageGrade())
				{
					c = vs[i];
					vs[i] = vs[i + 1];
					vs[i + 1] = c;
					sorto = false;
				}
		}
};

void Grupe::showG()
{
	for (int i = 0; i < n; i++)
		std::cout<<vs[i].GetName() << "\n";
};




int CmpName(Students x, Students y)
{
	int i=0;
	const char* a=x.GetName(), * b = y.GetName();
	while (a[i] != NULL && b[i] != NULL)
	{
		i++;
	}
	if (a[i] != NULL && b[i] == NULL)
		return 1;
	if (b[i] != NULL && a[i] == NULL)
		return -1;
	i = 0;
	while (a[i] != NULL && b[i] != NULL)
	{
		if (a[i] > b[i])
			return 1;
		if (a[i] < b[i])
			return -1;
		i++;
	}
	return -1;
}
int CmpGradeM(Students x, Students y)
{
	if (x.GetGradeM() > y.GetGradeM())
		return 1;
	else
		return -1;
}
int CmpGradeE(Students x, Students y)
{
	if (x.GetGradeE() > y.GetGradeE())
		return 1;
	else
		return -1;
}
int CmpGradeH(Students x, Students y)
{
	if (x.GetGradeH() > y.GetGradeH())
		return 1;
	else
		return -1;
}
int CmpAverageGrade(Students x, Students y)
{
	if (x.GetAverageGrade() > y.GetAverageGrade())
		return 1;
	else
		return -1;
}