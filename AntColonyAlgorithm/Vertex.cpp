#include "Vertex.h"

Vertex::Vertex(int x, int y, std::string& name)
{
	this->x = x;
	this->y = y;
	this->name = name;
}

int Vertex::getX()
{
	return x;
}

int Vertex::getY()
{
	return y;
}

std::string Vertex::getName()
{
	return name;
}

std::string Vertex::toString()
{
	return std::string("ÂÅĞØÈÍÀ: \t") +
		"name='" + name + "\'" +
		", x=" + std::to_string(x) +
		", y=" + std::to_string(y);
}