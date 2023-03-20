#include "Toyota.h"
Toyota::Toyota() {}
Toyota::~Toyota() {}
void Toyota::Name() const {
	printf("Toyota ");
}
double Toyota::GetFuelCapacity() const
{
	return fuel_capacity;
}
double Toyota::GetFuelConsumption(double lenght) const
{
	return lenght * fuel_consumption;
}
double Toyota::GetAverageSpeed(Weather::weather weather) const
{
	switch (weather)
	{
	case Weather::Rain:
		return 55;
		break;
	case Weather::Sunny:
		return 75;
		break;
	case Weather::Snow:
		return 45;
		break;
	default:
		break;
	}
}