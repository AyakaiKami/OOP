#ifndef CARH
#define CARH
#include <iostream>
#include "Weather.h"
class Car
{
protected:
	double fuel_capacity;
	double fuel_consumption;
public:
	    virtual double GetFuelCapacity() const = 0;
		virtual double GetFuelConsumption(double length=1) const = 0;
		virtual double GetAverageSpeed(Weather::weather weather) const = 0;
		virtual void Name() const = 0;
};
#endif // !CARH