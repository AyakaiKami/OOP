#include "Mazda.h"
Mazda::Mazda(){}
Mazda::~Mazda(){}
void Mazda::Name()const
{
	printf("Mazda");
}
double Mazda::GetFuelCapacity() const
{
	return fuel_capacity;
}
double Mazda::GetFuelConsumption(double lenght) const
{
	return lenght * fuel_consumption;
}
double Mazda::GetAverageSpeed(Weather::weather weather) const
{
	switch (weather)
	{
	case Weather::Rain:
		return 65;
		break;
	case Weather::Sunny:
		return 110;
		break;
	case Weather::Snow:
		return 49;
		break;
	default:
		break;
	}
}