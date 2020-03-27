#pragma once
#include "AntEdge.h"
#include "Vertex.h"
#include <vector>
#include <numeric>

class Ant
{
private:
	std::vector<int> tabuList;
	std::vector<double> allEdgesValues;
	double sumOfPathLength;
	double recentPathLength;
	int curVertex;

public:
	Ant(int startPosition);
	void addTabuEdge(AntEdge* path, int edge);
	int getLastTabuListElem();
	void addDistanceToSum(double distance);
	void initAnt(int startPos);
	void deleteTabuEdge(AntEdge* path, int edge);
	int getCurVertex();
	std::vector<int>& getTabuList();
	double getSumOfPathLength();
	void clear();
	std::vector<double>& getAllEdgesValues();
	bool isEnd(int amountOfVertexes);
	std::string getPath(std::vector<Vertex>& vertices);
	static std::string getPathByTabu(std::vector<Vertex>& vertices, std::vector<int>& tabuList);
	double getPathLength(std::vector<std::vector<AntEdge*>>& edges);
};
