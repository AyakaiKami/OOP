#ifndef FRACTIE
#define FRACTIE
#include <stdio.h>
class Fractie {
private:
	int numerator;
	int denominator;
public:
	Fractie();
	~Fractie();
	Fractie(int num_in, int den_in);
	Fractie(const char* in);
	Fractie simplify();
	void print();
	Fractie operator+(Fractie in);
	int operator[](const char* in);
	Fractie operator-(Fractie in);
	Fractie operator*(Fractie in);
	bool operator==(Fractie in);
};
#endif // !FRACTIE

