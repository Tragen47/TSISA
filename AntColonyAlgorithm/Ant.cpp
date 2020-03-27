#include "Ant.h"

Ant::Ant(int startPosition)
{
	initAnt(startPosition);
}

void Ant::addTabuEdge(AntEdge* path, int edge)
{
	if (std::find(tabuList.begin(), tabuList.end(), edge) == tabuList.end())
	{
		tabuList.push_back(edge);
		sumOfPathLength += path->getPathLength();
		recentPathLength = path->getPathLength();
		allEdgesValues.push_back(recentPathLength);
		curVertex = edge;
	}
}

int Ant::getLastTabuListElem()
{
	return tabuList[tabuList.size() - 1];
}

void Ant::addDistanceToSum(double distance)
{
	sumOfPathLength += distance;
	allEdgesValues.push_back(distance);
}

void Ant::initAnt(int startPos)
{
	tabuList.push_back(startPos);
	sumOfPathLength = 0.0;
	curVertex = startPos;
}

void Ant::deleteTabuEdge(AntEdge* path, int edge)
{
	if (std::find(tabuList.begin(), tabuList.end(), edge) != tabuList.end())
		sumOfPathLength -= path->getPathLength();
	tabuList.erase(std::find(tabuList.begin(), tabuList.end(), edge));

	delete[] path;
}

int Ant::getCurVertex()
{
	return curVertex;
}

std::vector<int>& Ant::getTabuList()
{
	return tabuList;
}

double Ant::getSumOfPathLength()
{
	return sumOfPathLength;
}

void Ant::clear()
{
	sumOfPathLength = 0;
	tabuList.clear();
	allEdgesValues.clear();
	recentPathLength = 0;
	curVertex = -1;
}

std::vector<double>& Ant::getAllEdgesValues()
{
	return allEdgesValues;
}

bool Ant::isEnd(int amountOfVertexes)
{
	return tabuList.size() == amountOfVertexes;
}

std::string Ant::getPath(std::vector<Vertex>& vertexes)
{
	return getPathByTabu(vertexes, this->tabuList);
}

std::string Ant::getPathByTabu(std::vector<Vertex>& vertexes, std::vector<int>& tabuList)
{
	if (tabuList.empty())
		return "ÍÈ ÎÄÍÎÃÎ ÓÇËÀ ÍÅ ÏÎÑÅÙÅÍÎ";
	if (tabuList.size() == 1)
		return "ÍÅ ÁÛËÎ ÑÎÂÅĞØÅÍÍÎ ÏÓÒÅØÅÑÒÂÈÉ.\nÍà÷àëüíûé óçåë: " + vertexes[tabuList[0]].toString();
	std::string path;
	for (int i = 0; i < tabuList.size(); i++)
		path.append(vertexes[tabuList[i]].getName()).append(" -> ");

	path.append(vertexes[tabuList[0]].getName());
	return path;
}

double Ant::getPathLength(std::vector<std::vector<AntEdge*>>& edges)
{
	if (tabuList.size() <= 1)
		return 0;

	double sum = 0;
	for (int i = 0; i < tabuList.size() - 1; i++)
		sum += edges[tabuList[i]][tabuList[i + 1]]->getPathLength();

	return sum;
}