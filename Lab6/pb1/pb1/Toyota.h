#ifndef TOYOTA
#define TOYOTA
#include "Car.h"
class Toyota : public Car {
private:
	double fuel_capacity = 35;
	double fuel_consumption=4;
public:
	Toyota();
	~Toyota();
	void Name() const;
	double GetFuelCapacity() const;
	double GetFuelConsumption(double length = 1) const;
	double GetAverageSpeed(Weather::weather weather ) const;
};
#endif // !TOYOTA
