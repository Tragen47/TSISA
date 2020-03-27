#include "SwarmAlgorithm.h"
#include <QtWidgets/QApplication>
#include <qlabel.h>
#include "Swarm.h"
#include "Particle.h"

#define SWARM_SIZE 100
inline QString CalculateSwarm(Swarm& swarm, int numOfFormula);

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QLabel label;
	label.setText("Computing...");
	label.show();

	QLabel output;
	output.setText(
		CalculateSwarm(Swarm(SWARM_SIZE, -500, 500), 0) +
		CalculateSwarm(Swarm(SWARM_SIZE, -1, 0), 1) +
		CalculateSwarm(Swarm(SWARM_SIZE, -500, 500), 2) +
		CalculateSwarm(Swarm(SWARM_SIZE, -500, 500), 3) +
		CalculateSwarm(Swarm(SWARM_SIZE, -500, 600), 3));

	label.hide();
	output.show();
	output.resize(output.width() + 200, output.height());
	output.show();
	return a.exec();
}

inline QString CalculateSwarm(Swarm& swarm, int numOfFormula)
{
	QString temp = "";
	swarm.CalculateMax(numOfFormula);
	temp += QString::fromStdString("\nG_MAX = " + std::to_string(swarm.getGlobalMaxSpeed()) + "\n");
	temp += QString::fromStdString("\nFUNC_MAX = " + std::to_string(Swarm::functionValue(swarm.getGlobalMaxSpeed(), numOfFormula)) + "\n");
	swarm.clearParticles();

	swarm.CalculateMin(numOfFormula);
	temp += QString::fromStdString("\nG_MIN = " + std::to_string(swarm.getGlobalMaxSpeed()) + "\n");
	temp += QString::fromStdString("\nFUNC_MIN = " + std::to_string(Swarm::functionValue(swarm.getGlobalMaxSpeed(), numOfFormula)) + "\n\n");
	swarm.clearParticles();

	return temp;
}

// Вычисления кубической функции со сдвигами
// Точка минимума - x = 0, функция в этой точке также равно 0, точка максимум  x = -20/18