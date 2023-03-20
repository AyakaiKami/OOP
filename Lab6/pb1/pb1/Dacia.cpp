#include "Dacia.h"
Dacia::Dacia(){}
Dacia::~Dacia(){}
void Dacia::Name() const {
	printf("Dacia");
}
double Dacia::GetFuelCapacity() const
{
	return fuel_capacity;
}
double Dacia::GetFuelConsumption(double lenght) const
{
	return lenght * fuel_consumption;
}
double Dacia::GetAverageSpeed(Weather::weather weather) const
{
	switch (weather)
	{
	case Weather::Rain:
		return 50;
		break;
	case Weather::Sunny:
		return 70;
		break;
	case Weather::Snow:
		return 40;
		break;
	default:
		break;
	}
}