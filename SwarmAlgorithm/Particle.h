#pragma once
class Particle
{
private:
	double currentSpeed;
	double localMaxSpeed;
	double x;

	void NextIteration(double globalMaxSpeed, double minValue, double maxValue, int numOfFormula);

public:
	Particle(double currentSpeed, double localMaxSpeed, double x);

	double getLocalMaxSpeed();
	void setLocalMaxSpeed(double localMaxSpeed);
	double getX();
	void NextIterationMax(double globalMaxSpeed, double minValue, double maxValue, int numOfFormula);
	void NextIterationMin(double globalMaxSpeed, double minValue, double maxValue, int numOfFormula);
};