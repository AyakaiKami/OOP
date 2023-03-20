#ifndef FORD
#define FORD
#include "Car.h"
class Ford : public Car {
private:
	double fuel_capacity = 50;
	double fuel_consumption = 6;
public:
	Ford();
	~Ford();
	void Name() const;
	double GetFuelCapacity() const;
	double GetFuelConsumption(double length = 1) const;
	double GetAverageSpeed(Weather::weather weather ) const;
};
#endif // !FORD


