#pragma once
#include <functional>
#include "Particle.h"

#define ITERATIONS 100000

class Swarm
{
private:
	std::vector<Particle> particles;
	size_t swarmSize;
	double minValue;
	double maxValue;
	double globalMaxSpeed;

	double Calculate(const int numOfFormula, std::function<bool(double, double)>);

public:
	Swarm(size_t swarmSize, double minValue, double maxValue);
	static double functionValue(double x, const int numOfFormula);
	void clearParticles();
	double getGlobalMaxSpeed();
	double CalculateMax(const int numOfFormula);
	double CalculateMin(const int numOfFormula);
};