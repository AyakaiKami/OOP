#include "Mercedes.h"
Mercedes::Mercedes() {}
Mercedes::~Mercedes() {}
void Mercedes::Name() const 
{
	printf("Mercedes");
}
double Mercedes::GetFuelCapacity() const
{
	return fuel_capacity;
}
double Mercedes::GetFuelConsumption(double lenght) const
{
	return lenght * fuel_consumption;
}
double Mercedes::GetAverageSpeed(Weather::weather weather) const
{
	switch (weather)
	{
	case Weather::Rain:
		return 90;
		break;
	case Weather::Sunny:
		return 140;
		break;
	case Weather::Snow:
		return 60;
		break;
	default:
		break;
	}
}