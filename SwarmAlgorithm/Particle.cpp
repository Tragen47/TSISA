#include <random>
#include "Particle.h"
#include "Swarm.h"

Particle::Particle(double currentSpeed, double localMaxSpeed, double x)
{
	this->currentSpeed = currentSpeed;
	this->localMaxSpeed = localMaxSpeed;
	this->x = x;
}

double Particle::getLocalMaxSpeed()
{
	return localMaxSpeed;
}

void Particle::setLocalMaxSpeed(double localMaxSpeed)
{
	this->localMaxSpeed = localMaxSpeed;
}

double Particle::getX()
{
	return x;
}

void Particle::NextIteration(double globalMaxSpeed, double minValue, double maxValue, int numOfFormula)
{
	double t = 1; //Какой-то коэффициент
	double a, b;
	a = (double)rand() / RAND_MAX;
	b = 1 - a;
	double y = (double)rand() / RAND_MAX; //Коэффициент сдерживания окружающей среды
	currentSpeed = (y * (currentSpeed + a * (localMaxSpeed - x) + b * (globalMaxSpeed - x)));
	x += t * currentSpeed;

	if (x < minValue)
		x = minValue;
	if (x > maxValue)
		x = maxValue;
}

void Particle::NextIterationMax(double globalMaxSpeed, double minValue, double maxValue, int numOfFormula)
{
	NextIteration(globalMaxSpeed, minValue, maxValue, numOfFormula);
	if (Swarm::functionValue(x, numOfFormula) > Swarm::functionValue(localMaxSpeed, numOfFormula))
		localMaxSpeed = x;
}

void Particle::NextIterationMin(double globalMaxSpeed, double minValue, double maxValue, int numOfFormula)
{
	NextIteration(globalMaxSpeed, minValue, maxValue, numOfFormula);
	if (Swarm::functionValue(x, numOfFormula) < Swarm::functionValue(localMaxSpeed, numOfFormula))
		localMaxSpeed = x;
}