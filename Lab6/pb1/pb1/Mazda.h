#ifndef MAZDA
#define MAZDA
#include "Car.h"
class Mazda : public Car
{
private:
	double fuel_capacity = 45;
	double fuel_consumption = 5;

public:
	Mazda();
	~Mazda();
	void Name() const;
	double GetFuelCapacity() const;
	double GetFuelConsumption(double length = 1) const;
	double GetAverageSpeed(Weather::weather weather ) const;
};
#endif // !MAZDA

