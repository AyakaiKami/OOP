#ifndef CIRCUIT
#define CIRCUIT
#include "Car.h"
#include "Dacia.h"
#include "Ford.h"
#include "Mazda.h"
#include "Mercedes.h"
#include "Toyota.h"
class Circuit
{
	int nr_masinni;
	Car *cars[256];
	Weather::weather weather;
	double length;
	Car* Ranks[256];
	int ranks_nr = 0;
	Car* DidNotFinish[256];
	int DNF_nr = 0;

public:
	Circuit();
	~Circuit();
	void SetWeather(Weather::weather weather_in);
	void SetLength(double length_in);
	void AddCar(Car *car_new);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();

};
#endif // !CIRCUIT

