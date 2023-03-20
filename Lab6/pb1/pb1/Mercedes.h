#ifndef MERCEDES
#define MERCEDES
#include "Car.h"
class Mercedes : public Car {
private:
	double fuel_capacity = 50;
	double fuel_consumption = 6;
public:
	Mercedes();
	~Mercedes();
	void Name()const;
	double GetFuelCapacity() const;
	double GetFuelConsumption(double length = 1) const;
	double GetAverageSpeed(Weather::weather weather ) const;
};
#endif // !Ford

