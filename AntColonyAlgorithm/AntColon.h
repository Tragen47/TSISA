#pragma once
#include "Ant.h"
#include "AntEdge.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <iomanip>
#include <sstream>
#include <assert.h>

#define ALPHA 1.0
#define BETA 5.0

/* Интенсивность / Испарение */
#define RHO 0.5	

#define Q 100.0

#define MAX_VERTICES 27
#define MAX_ANTS 30
#define MAX_DISTANCE 200
#define SCALE 13
#define MAX_TOURS 20
#define MAX_TIME (MAX_TOURS * MAX_VERTICES)
#define SCALE_NUM std::pow(10, SCALE)
#define EPS (1.0 / SCALE_NUM) * 10

class AntColony
{
public:
	static double best;
	static int bestIndex;
	static std::vector<double> allEdgesValues;
	static bool isBestChanged;
	static std::string bestPath;
	static double INIT_PHEROMONE;

private:
	std::vector<Ant> ants;
	std::vector<Vertex> vertices;
	std::vector<std::vector<AntEdge*>> edges;
	std::string names[52] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O",
			"P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };

public:
	AntColony(int amountOfVertex, int amountOfAnts);

	int SimulateAnts();
	void RestartAnts();
	double GetAntProduct(int from, int to);
	int SelectNextCity(int ant);
	void UpdateTrails();

	class BrutalBestInside
	{
	public:
		double sum;
		std::vector<int> tabuList;

		BrutalBestInside(double sum, std::vector<int>& tabuList);
	};

	void ShowVerticesMatrix();
};

bool operator <(const AntColony::BrutalBestInside& left, const AntColony::BrutalBestInside& right);