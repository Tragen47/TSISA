#include "AntColon.h"

inline std::string MakeRow(std::vector<std::string>& input)
{
	int maxLength = SCALE + 2;
	std::string titleRow("|");
	std::string subTitleRow("\n|");
	for (std::string value : input)
	{
		int localLength = maxLength - value.length();
		int localLengthL = localLength / 2;
		int localLengthR = (localLength - localLengthL);
		for (int k = 0; k < localLengthL; k++)
			titleRow.append(" ");
		titleRow.append(value);
		for (int k = 0; k < localLengthR; k++)
			titleRow.append(" ");
		titleRow.append("|");
		for (int k = 0; k < maxLength; k++)
			subTitleRow.append("_");
		subTitleRow.append("|");
	}
	titleRow.append(subTitleRow);
	return titleRow;
}

void AntColony::ShowVerticesMatrix()
{
	std::vector<std::string> temp;
	temp.push_back(" ");
	for (Vertex v : vertices)
		temp.push_back(v.getName());
	std::cout << MakeRow(temp) << std::endl;

	temp.clear();
	for (int i = 0; i < vertices.size(); i++)
	{
		temp.push_back(vertices[i].getName());
		for (int j = 0; j < vertices.size(); j++)
		{
			std::stringstream value;
			if (j != i)
				value << std::setprecision(SCALE) << edges[i][j]->getPathLength();
			else
				value << "-";
			temp.push_back(value.str());
		}
		std::cout << MakeRow(temp) << std::endl;
		temp.clear();
	}
	std::cout << "\n" << std::endl;
}