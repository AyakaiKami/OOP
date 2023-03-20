#ifndef DACIA
#define DACIA
#include "Car.h"
class Dacia : public Car {
private:
	double fuel_capacity=30;
	double fuel_consumption=5;
public:
	Dacia();
	~Dacia();
	void Name() const;
	double GetFuelCapacity() const;
	double GetFuelConsumption(double length=1) const;
	double GetAverageSpeed(Weather::weather weather) const;
};
#endif // !DACIA
