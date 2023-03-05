#include "Math.h"
 int Math::Add(int a, int b)
{
	return a + b;
};
 
 int Math::Add(int a, int b, int c)
{
	return a + b + c;
};
int Math::Add(double a, double b)
{
	return a + b;
}
int Math::Add(double a, double b,double c)
{
	return a + b + c;
}
int Math::Mul(int a, int b)
{
	return a * b;
};

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
};
int Math::Mul(double a, double b)
{
	return a * b;
}
int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}
int Math::Add(int count, int* v)
{
	int s = 0;
	for (int i = 0; i < count; i++)
		s += v[i];
	return s;
}
char* Math::Add(const char* a, const char* b)
{
	int t = 0, i = 0;
	do {
		t++;
	} while (a[t] != '\0');
	do {
		i++;
	} while (b[i] != '\0');
	std::cout << t + i<<std::endl;
	char* c = new char[t + i + 1]; int k = 0;
	t = 0;i = 0;
	while(a[t]!='\0')
	{
		c[k++] = a[t++];
	}
	while (b[i] != '\0')
	{
		c[k++] = b[i++];
	}
	c[k] = '\0';
	return c;
}