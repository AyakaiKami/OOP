#ifndef StudentsH
#define StudentsH
#include <string.h>
class Students
{
private:
	 const char* Names;
	float GradeM, GradeE, GradeH;
public:
	void SetName(const char* x);
	 const char* GetName();

	void SetGradeM(float x);
	void SetGradeE(float x);
	void SetGradeH(float x);

	float GetGradeM();
	float GetGradeE();
	float GetGradeH();

	float GetAverageGrade();
};
int CmpName(Students x,Students y);
int CmpGradeM(Students x, Students y);
int CmpGradeE(Students x, Students y);
int CmpGradeH(Students x, Students y);
int CmpAverageGrade(Students x, Students y);

class Grupe
{
	public:
		Students vs[256];
		int n;
		void sortS();
		void showG();
};
#endif 
