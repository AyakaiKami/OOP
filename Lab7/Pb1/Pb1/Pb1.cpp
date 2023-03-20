#include <iostream>
float operator""_Kelvin(const char* x)
{
	float value = 0;
	while ((*x) != 0)
	{
		value = value * 10 + (*x) - '0';
		x++;
	}
	value = value +273.15;
	return value;
}
float operator""_Fahrenheit(const char* x)
{
	float value = 0;
	while ((*x) != 0)
	{
		value = value * 10 + (*x) - '0';
		x++;
	}
	value = value * 1.8 + 32;
	return value;
}
int main() 
{
float a = 300_Kelvin;    
float b = 120_Fahrenheit;    
printf("%f   %f", a, b);
return 0; 
}