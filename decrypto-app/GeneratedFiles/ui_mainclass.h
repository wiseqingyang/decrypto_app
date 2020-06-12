/********************************************************************************
** Form generated from reading UI file 'mainclass.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCLASS_H
#define UI_MAINCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainClassClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *label;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainClassClass)
    {
        if (MainClassClass->objectName().isEmpty())
            MainClassClass->setObjectName(QStringLiteral("MainClassClass"));
        MainClassClass->resize(400, 220);
        centralWidget = new QWidget(MainClassClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(350, 68, 28, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(25, 75, 54, 12));
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(90, 30, 89, 16));
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(centralWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(200, 30, 89, 16));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 140, 75, 23));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(65, 70, 275, 20));
        lineEdit->setReadOnly(true);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(false);
        pushButton_3->setGeometry(QRect(30, 140, 0, 23));
        MainClassClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainClassClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        MainClassClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainClassClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainClassClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainClassClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainClassClass->setStatusBar(statusBar);

        retranslateUi(MainClassClass);

        QMetaObject::connectSlotsByName(MainClassClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainClassClass)
    {
        MainClassClass->setWindowTitle(QApplication::translate("MainClassClass", "\344\270\223\347\224\250\350\247\243\345\257\206", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainClassClass", "...", Q_NULLPTR));
        label->setText(QApplication::translate("MainClassClass", "\346\272\220\347\233\256\345\275\225", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainClassClass", "\350\247\243\345\257\206\346\226\207\344\273\266\345\244\271", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainClassClass", "\350\247\243\345\257\206\345\215\225\347\213\254\346\226\207\344\273\266", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainClassClass", "\350\247\243\345\257\206", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainClassClass", "\345\212\240\345\257\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainClassClass: public Ui_MainClassClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCLASS_H
