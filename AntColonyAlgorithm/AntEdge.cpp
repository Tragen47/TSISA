#include "AntEdge.h"

AntEdge::AntEdge(const AntEdge* antEdge)
{
	this->pathLength = antEdge->pathLength;
	this->amountOfPheromones = antEdge->amountOfPheromones;
}

AntEdge::AntEdge(double pathLength, double amountOfPheromones)
{
	this->pathLength = pathLength;
	this->amountOfPheromones = amountOfPheromones;
}

double AntEdge::getPathLength()
{
	return pathLength;
}

double AntEdge::getAmountOfPheromones()
{
	return amountOfPheromones;
}

void AntEdge::setAmountOfPheromones(double amountOfPheromones)
{
	this->amountOfPheromones = amountOfPheromones;
}

void AntEdge::addPheromones(double amountOfPheromones)
{
	this->amountOfPheromones += amountOfPheromones;
}

void AntEdge::multiplyPheromones(double amountOfPheromones)
{
	this->amountOfPheromones *= amountOfPheromones;
}