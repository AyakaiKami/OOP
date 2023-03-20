#include "Circuit.h"

Circuit::Circuit()
{
	nr_masinni = 0;
	ranks_nr = 0;
	DNF_nr = 0;
	length = 0;
}
Circuit::~Circuit()
{
	length = 0;
}
void Circuit::SetLength(double length_in)
{
	length = length_in;
}
void Circuit::AddCar(Car *car_new)
{
	cars[nr_masinni] = car_new;
	nr_masinni++;
}
void Circuit::Race()
{
	for(int i=0;i<nr_masinni;i++)
		if (cars[i]->GetFuelConsumption(length) < cars[i]->GetFuelCapacity())
		{
			Ranks[ranks_nr] = cars[i];
			ranks_nr++;
		}
		else
		{
			DidNotFinish[DNF_nr] = cars[i];
			DNF_nr++;
		}
	for(int i=0;i<ranks_nr-1;i++)
		for(int j=i+1;j<ranks_nr;j++)
			if (Ranks[i]->GetAverageSpeed(weather) > Ranks[j]->GetAverageSpeed(weather))
			{
				Car* cop = Ranks[i];
				Ranks[i] = Ranks[j];
				Ranks[j] = cop;
			}
}
void Circuit::ShowFinalRanks()
{
	printf("Ranks are \n");
	for (int i = 0; i < ranks_nr; i++)
	{
		printf("%d", i+1);
		Ranks[i]->Name();
		printf("\n");
	}

}
void Circuit::ShowWhoDidNotFinish()
{
	printf("The following have not finish the race \n");
	for (int i = 0; i < DNF_nr; i++)
	{
		DidNotFinish[i]->Name();
		printf("\n");
	}
}
void Circuit::SetWeather(Weather::weather weather_in)
{
	weather = weather_in;
}