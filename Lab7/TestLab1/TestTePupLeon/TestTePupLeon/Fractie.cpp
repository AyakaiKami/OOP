#include "Fractie.h"
Fractie::Fractie() {}
Fractie::~Fractie(){}
Fractie::Fractie(int num_in, int den_in)
{
	numerator = num_in;
	denominator = den_in;
}
Fractie::Fractie(const char* in)
{
	denominator = 1;
	int x = 0,i=0;
	while (in[i] != '\0')
	{
		if (in[i] >= '0' && in[i] <= '9')
		{
			x = x * 10 + (in[i] - '0');
		}
		i++;
	}
	numerator = x;
}
void Fractie::print()
{
	printf("%d/%d", numerator, denominator);
}
Fractie Fractie::operator+(Fractie in)
{
	int a = denominator, b = in.denominator;
	///this->simplify();
	///in.simplify();
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
		{
			b = b - a;
		}
	}
	int cmmdc = a;
	int ss, sj;
	ss =numerator * in.denominator+in.numerator*denominator;
	sj = denominator * in.denominator;
	Fractie dum(ss, sj);
	return dum;
}
int Fractie::operator[](const char* in)
{
	if (in == "numerator")
		return numerator;
	if (in == "denominator")
		return denominator;
	return 0;
}
Fractie Fractie::operator-(Fractie in)
{
	int a = denominator, b = in.denominator;
	///this->simplify();
	///in.simplify();
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
		{
			b = b - a;
		}
	}
	int cmmdc = a;
	int ss, sj;
	ss = numerator * in.denominator - in.numerator * denominator;
	sj = denominator * in.denominator;
	Fractie dum(ss, sj);
	return dum;
}
Fractie Fractie::operator*(Fractie in)
{
	Fractie dum(numerator * in.numerator, denominator * in.denominator);
	return dum;
}
Fractie Fractie::simplify()
{
	int a = numerator, b = denominator;
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
		{
			b = b - a;
		}
	}
	int cmmdc = a;
	Fractie dum(numerator / cmmdc, denominator / cmmdc);
	numerator = numerator / cmmdc;
	denominator = denominator / cmmdc;
	return dum;
}
bool Fractie::operator==(Fractie in)
{
	Fractie f1 = this->simplify(), f2 = in.simplify();
	if (f1.numerator != f2.numerator)
		return false;
	if (f1.denominator != f2.denominator)
		return false;
	return true;
}