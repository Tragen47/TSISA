#include "AntColon.h"

AntColony::AntColony(int amountOfVertex, int amountOfAnts)
{
	isBestChanged = false;
	amountOfVertex =  std::min(amountOfVertex, MAX_VERTICES);
	amountOfAnts = std::min(amountOfAnts, MAX_ANTS);

	best = MAX_TOURS;
	edges.resize(amountOfVertex);
	for (size_t i = 0; i < amountOfVertex; i++)
		edges[i].resize(amountOfVertex);

	for (int i = 0; i < amountOfVertex; i++)
		vertices.push_back(Vertex((size_t)(((double)rand() / RAND_MAX) * MAX_DISTANCE), (size_t)(((double)rand() / RAND_MAX) * MAX_DISTANCE), names[i]));
	INIT_PHEROMONE = (1.0 / vertices.size());
	for (int from = 0; from < amountOfVertex; from++)
		for (int to = 0; to < amountOfVertex; to++)
			if (from == to)
				edges[from][to] = NULL;
			else
				if (edges[from][to] == NULL || edges[from][to]->getPathLength() == 0)
				{
					int xd = abs(vertices[from].getX() - vertices[to].getX());
					int yd = abs(vertices[from].getY() - vertices[to].getY());
					edges[from][to] = new AntEdge((round(pow(xd * xd + yd * yd, (1.0 / 2.0)) * SCALE_NUM) / SCALE_NUM), INIT_PHEROMONE);
					edges[to][from] = new AntEdge(*edges[from][to]);
				}

	int vertexIndex = 0;
	for (int i = 0; i < amountOfAnts; i++) 
	{
		if (vertexIndex >= vertices.size()) 
			vertexIndex = 0;
		ants.push_back(Ant(vertexIndex++));
	}
	ShowVerticesMatrix();
}

int AntColony::SimulateAnts()
{
	int moving = 0;
	for (int antNum = 0; antNum < ants.size(); antNum++)
		/* ”бедитьс€, что муравью есть куда идти */
		if (ants[antNum].getTabuList().size() < vertices.size())
		{
			int nextVertex = SelectNextCity(antNum);
			ants[antNum].addTabuEdge(edges[ants[antNum].getCurVertex()][nextVertex], nextVertex);

			/* ќбработка окончани€ путешестви€ (из последнего города в первый */
			if (ants[antNum].getTabuList().size() == vertices.size())
				ants[antNum].addDistanceToSum(edges[ants[antNum].getLastTabuListElem()][ants[antNum].getTabuList()[0]]->getPathLength());
			moving++;
		}
	return moving;
}

void AntColony::RestartAnts()
{
	int to = 0;
	for (int antNum = 0; antNum < ants.size(); antNum++) 
	{
		if (ants[antNum].getSumOfPathLength() < best)
		{
			best = ants[antNum].getSumOfPathLength();
			bestIndex = antNum;
			isBestChanged = true;
			bestPath = ants[antNum].getPath(vertices);
			allEdgesValues = ants[antNum].getAllEdgesValues();
		}

		ants[antNum].clear();
		ants[antNum].initAnt(to++);
		if (to >= vertices.size())
			to = 0;
	}
}

double AntColony::GetAntProduct(int from, int to)
{
	return pow(edges[from][to]->getAmountOfPheromones(), ALPHA) *
		pow((1.0 / edges[from][to]->getPathLength()), BETA);
}

int AntColony::SelectNextCity(int ant)
{
	int from, to;
	double denom = 0.0;

	/* ¬ыбрать следующий город */
	from = ants[ant].getCurVertex();

	/* –асчет знаменател€ */
	std::vector<int> temp = ants[ant].getTabuList();
	for (to = 0; to < vertices.size(); to++)
		if (std::find(temp.begin(), temp.end(), to) == temp.end())
			denom += GetAntProduct(from, to);

	if (denom == 0.0)
		throw ("DENOM MUST BE LARGER THAN 0.0");
	do
	{
		double p = 0.0;

		to++;
		if (to >= vertices.size())
			to = 0;

		if (std::find(temp.begin(), temp.end(), to) == temp.end())
		{
			p = GetAntProduct(from, to) / denom;
			//—имулируем веро€тность попадени€, чем больше будет число P, тем больше будет шанс, что муравей пойдЄт сюда,
			// а соответственно и больше феромонов будет на дороге. “ака€ цепочка должна вы€вить самый короткий путь
			if (((double)rand() / RAND_MAX) < p)
				break;
		}
	}
	while (true);

	return to;
}

void AntColony::AntColony::UpdateTrails()
{
	int from, to;
	/* »спарение фермента */
	for (from = 0; from < vertices.size(); from++)
		for (to = 0; to < vertices.size(); to++)
			if (to != from)
			{
				edges[from][to]->multiplyPheromones((1.0 - RHO));
				if (edges[from][to]->getAmountOfPheromones() <= EPS)
					edges[from][to]->setAmountOfPheromones(INIT_PHEROMONE);
			}

	/* Ќанесение нового фермента */
	/* ƒл€ пути каждого муравь€ */
	for (Ant ant : ants)
		/* ќбновл€ем каждый шаг пути */
		for (int i = 0; i < vertices.size(); i++)
		{
			from = ant.getTabuList()[i];
			if (i < vertices.size() - 1)
				to = ant.getTabuList()[i + 1];
			else
				to = ant.getTabuList()[0];

			//формула 2.2 из методички Q/L(t)
			edges[from][to]->addPheromones((Q / ant.getSumOfPathLength()));
			edges[to][from]->setAmountOfPheromones(edges[from][to]->getAmountOfPheromones());
		}
	for (from = 0; from < vertices.size(); from++)
		for (to = 0; to < vertices.size(); to++)
			if (edges[from][to] != NULL)
				edges[from][to]->multiplyPheromones(RHO);
}

AntColony::BrutalBestInside::BrutalBestInside(double sum, std::vector<int>& tabuList)
{
	this->sum = sum;
	this->tabuList = tabuList;
}

bool operator <(const AntColony::BrutalBestInside& left, const AntColony::BrutalBestInside& right)
{
	return left.sum < right.sum;
}

double AntColony::best;
int AntColony::bestIndex;
std::vector<double> AntColony::allEdgesValues;
bool AntColony::isBestChanged;
std::string AntColony::bestPath;
double AntColony::INIT_PHEROMONE;