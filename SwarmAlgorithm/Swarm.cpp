#include <vector>
#include "Particle.h"
#include "Swarm.h"

Swarm::Swarm(size_t swarmSize, double minValue, double maxValue)
{
	this->swarmSize = swarmSize;
	this->minValue = minValue;
	this->maxValue = maxValue;
}

double Swarm::functionValue(double x, const int numOfFormula)
{
	switch (numOfFormula)
	{
	case 0:
		return (-x * sin(pow(abs(x), (1.0 / 2.0))));
	case 1:
		return 3 * pow(x, 3) + 5 * pow(x, 2);
	case 2:
		return (x * cos(pow(abs(x), (1.0 / 4.0))));
	case 3:
		return (x * cos(pow(x, (1.0 / 4.0))));
	}
}

void Swarm::clearParticles()
{
	particles.clear();
}

double Swarm::getGlobalMaxSpeed()
{
	return globalMaxSpeed;
}

double Swarm::Calculate(const int numOfFormula, std::function<bool(double, double)> func)
{
	for (int i = 0; i < swarmSize; i++)
		particles.push_back(Particle(0, 0, minValue + ((double)rand() / RAND_MAX) * (maxValue - minValue)));
	globalMaxSpeed = particles[0].getLocalMaxSpeed();
	for (Particle p : particles)
		if (func(functionValue(p.getX(), numOfFormula), functionValue(p.getLocalMaxSpeed(), numOfFormula)))
		{
			p.setLocalMaxSpeed(p.getX());
			if (func(functionValue(p.getLocalMaxSpeed(), numOfFormula), functionValue(globalMaxSpeed, numOfFormula)))
				globalMaxSpeed = p.getLocalMaxSpeed();
		}
	for (int i = 0; i < ITERATIONS; i++)
	{
		//Calculate speed
		for (Particle p : particles)
			p.NextIterationMax(globalMaxSpeed, minValue, maxValue, numOfFormula);

		//Calculate the max/min speed
		for (Particle p : particles)
			if (func(Swarm::functionValue(p.getLocalMaxSpeed(), numOfFormula), Swarm::functionValue(globalMaxSpeed, numOfFormula)))
				globalMaxSpeed = p.getLocalMaxSpeed();
	}
	return globalMaxSpeed;
}

double Swarm::CalculateMax(const int numOfFormula)
{
	return Calculate(numOfFormula, std::greater<double>());
}

double Swarm::CalculateMin(const int numOfFormula)
{
	return Calculate(numOfFormula, std::less<double>());
}