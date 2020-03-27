#pragma once

#include <QtWidgets/QMainWindow>
#include <qlabel.h>
#include "ui_SwarmAlgorithm.h"

class SwarmAlgorithm : public QMainWindow
{
	Q_OBJECT

public:
	SwarmAlgorithm(QWidget *parent = Q_NULLPTR);

private:
	Ui::SwarmAlgorithmClass ui;
};
