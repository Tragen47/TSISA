/********************************************************************************
** Form generated from reading UI file 'SwarmAlgorithm.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWARMALGORITHM_H
#define UI_SWARMALGORITHM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SwarmAlgorithmClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SwarmAlgorithmClass)
    {
        if (SwarmAlgorithmClass->objectName().isEmpty())
            SwarmAlgorithmClass->setObjectName(QString::fromUtf8("SwarmAlgorithmClass"));
        SwarmAlgorithmClass->resize(600, 400);
        centralWidget = new QWidget(SwarmAlgorithmClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        SwarmAlgorithmClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SwarmAlgorithmClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        SwarmAlgorithmClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SwarmAlgorithmClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SwarmAlgorithmClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SwarmAlgorithmClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SwarmAlgorithmClass->setStatusBar(statusBar);

        retranslateUi(SwarmAlgorithmClass);

        QMetaObject::connectSlotsByName(SwarmAlgorithmClass);
    } // setupUi

    void retranslateUi(QMainWindow *SwarmAlgorithmClass)
    {
        SwarmAlgorithmClass->setWindowTitle(QCoreApplication::translate("SwarmAlgorithmClass", "SwarmAlgorithm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SwarmAlgorithmClass: public Ui_SwarmAlgorithmClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWARMALGORITHM_H
