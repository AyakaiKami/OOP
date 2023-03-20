#include "Ford.h"
Ford::Ford() {}
Ford::~Ford() {}
void Ford::Name()const {
	printf("Ford");
}
double Ford::GetFuelCapacity() const
{
	return fuel_capacity;
}
double Ford::GetFuelConsumption(double lenght) const
{
	return lenght * fuel_consumption;
}
double Ford::GetAverageSpeed(Weather::weather weather) const
{
	switch (weather)
	{
	case Weather::Rain:
		return 70;
		break;
	case Weather::Sunny:
		return 100;
		break;
	case Weather::Snow:
		return 35;
		break;
	default:
		break;
	}
}