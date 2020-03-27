#include <iostream>
#include <vector>
#include <time.h>
#include "AntColon.h"

void ExecuteAntAlgorithm()
{
	int curTime = 0;
	AntColony AntColony(11, 30);
	//Один цикл времени будет равен amountOfVertex
	while (curTime++ < MAX_TIME * 2)
		if (AntColony.SimulateAnts() == 0)
		{
			AntColony.UpdateTrails();
			if (curTime != MAX_TIME * 2)
				AntColony.RestartAnts();
			if (AntColony::isBestChanged)
				std::cout << "ВРЕМЯ " + std::to_string(curTime) + " " + std::to_string(AntColony::best) << std::endl;
			AntColony::isBestChanged = false;
		}

	std::cout << "\n\nЛучшее расстояние: " + std::to_string(AntColony::best) << std::endl;
	std::cout << "Лучший индекс: " + std::to_string(AntColony::bestIndex) << std::endl;
	std::cout << "Лучший маршрут: " + AntColony::bestPath << std::endl;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	ExecuteAntAlgorithm();
}