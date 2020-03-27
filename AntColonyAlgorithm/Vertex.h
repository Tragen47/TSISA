#pragma once
#include <vector>
#include <string>

class Vertex
{
private:
	int x, y;
	std::string name;

public:
	Vertex(int x, int y, std::string& name);
	int getX();
	int getY();
	std::string getName();
	std::string toString();
};