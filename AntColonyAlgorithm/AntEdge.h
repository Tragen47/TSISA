#pragma once
class AntEdge
{
private:
	double pathLength;
	double amountOfPheromones;

public:
	AntEdge(const AntEdge* antEdge);
	AntEdge(double pathLength, double amountOfPheromones);
	double getPathLength();
	double getAmountOfPheromones();
	void setAmountOfPheromones(double amountOfPheromones);
	void addPheromones(double amountOfPheromones);
	void multiplyPheromones(double amountOfPheromones);
};