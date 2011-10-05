/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created: Thu Jul 14 13:22:19 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main
{
public:
    QAction *actionAbout;
    QWidget *centralWidget;
    QTabWidget *tabs;
    QWidget *rechnen;
    QPushButton *calcButton1;
    QLabel *labelInput1;
    QLineEdit *inputIntervall;
    QGroupBox *settingsRechnen;
    QPushButton *clearButton1;
    QWidget *nullstellen;
    QLineEdit *inputFunction;
    QLabel *labelInput21;
    QPushButton *calcButton2;
    QPushButton *clearButton2;
    QLineEdit *inputDerivate;
    QLabel *labelInput22;
    QLabel *labelInput23;
    QLineEdit *inputStart;
    QWidget *gleichungssystem;
    QLineEdit *inputA;
    QLineEdit *inputD;
    QLineEdit *inputC;
    QLineEdit *inputB;
    QLineEdit *inputE;
    QLineEdit *inputF;
    QLabel *label34;
    QLabel *label32;
    QLabel *label31;
    QLabel *label33;
    QPushButton *calcButton3;
    QGroupBox *settingsGleichungssystem;
    QCheckBox *checkBox31;
    QPushButton *clearButton3;
    QTextEdit *output;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Main)
    {
        if (Main->objectName().isEmpty())
            Main->setObjectName(QString::fromUtf8("Main"));
        Main->resize(500, 600);
        actionAbout = new QAction(Main);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(Main);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabs = new QTabWidget(centralWidget);
        tabs->setObjectName(QString::fromUtf8("tabs"));
        tabs->setGeometry(QRect(20, 10, 460, 210));
        rechnen = new QWidget();
        rechnen->setObjectName(QString::fromUtf8("rechnen"));
        calcButton1 = new QPushButton(rechnen);
        calcButton1->setObjectName(QString::fromUtf8("calcButton1"));
        calcButton1->setGeometry(QRect(220, 140, 114, 32));
        labelInput1 = new QLabel(rechnen);
        labelInput1->setObjectName(QString::fromUtf8("labelInput1"));
        labelInput1->setGeometry(QRect(10, 10, 62, 20));
        inputIntervall = new QLineEdit(rechnen);
        inputIntervall->setObjectName(QString::fromUtf8("inputIntervall"));
        inputIntervall->setGeometry(QRect(70, 10, 370, 22));
        settingsRechnen = new QGroupBox(rechnen);
        settingsRechnen->setObjectName(QString::fromUtf8("settingsRechnen"));
        settingsRechnen->setGeometry(QRect(10, 50, 430, 80));
        clearButton1 = new QPushButton(rechnen);
        clearButton1->setObjectName(QString::fromUtf8("clearButton1"));
        clearButton1->setGeometry(QRect(330, 140, 114, 32));
        tabs->addTab(rechnen, QString());
        settingsRechnen->raise();
        calcButton1->raise();
        labelInput1->raise();
        inputIntervall->raise();
        clearButton1->raise();
        nullstellen = new QWidget();
        nullstellen->setObjectName(QString::fromUtf8("nullstellen"));
        inputFunction = new QLineEdit(nullstellen);
        inputFunction->setObjectName(QString::fromUtf8("inputFunction"));
        inputFunction->setGeometry(QRect(70, 10, 370, 22));
        labelInput21 = new QLabel(nullstellen);
        labelInput21->setObjectName(QString::fromUtf8("labelInput21"));
        labelInput21->setGeometry(QRect(30, 10, 40, 20));
        calcButton2 = new QPushButton(nullstellen);
        calcButton2->setObjectName(QString::fromUtf8("calcButton2"));
        calcButton2->setGeometry(QRect(220, 140, 114, 32));
        clearButton2 = new QPushButton(nullstellen);
        clearButton2->setObjectName(QString::fromUtf8("clearButton2"));
        clearButton2->setGeometry(QRect(330, 140, 114, 32));
        inputDerivate = new QLineEdit(nullstellen);
        inputDerivate->setObjectName(QString::fromUtf8("inputDerivate"));
        inputDerivate->setGeometry(QRect(70, 50, 370, 22));
        labelInput22 = new QLabel(nullstellen);
        labelInput22->setObjectName(QString::fromUtf8("labelInput22"));
        labelInput22->setGeometry(QRect(30, 50, 40, 20));
        labelInput23 = new QLabel(nullstellen);
        labelInput23->setObjectName(QString::fromUtf8("labelInput23"));
        labelInput23->setGeometry(QRect(110, 90, 90, 20));
        inputStart = new QLineEdit(nullstellen);
        inputStart->setObjectName(QString::fromUtf8("inputStart"));
        inputStart->setGeometry(QRect(200, 90, 120, 22));
        tabs->addTab(nullstellen, QString());
        gleichungssystem = new QWidget();
        gleichungssystem->setObjectName(QString::fromUtf8("gleichungssystem"));
        inputA = new QLineEdit(gleichungssystem);
        inputA->setObjectName(QString::fromUtf8("inputA"));
        inputA->setGeometry(QRect(10, 10, 90, 22));
        QFont font;
        font.setStyleStrategy(QFont::PreferDefault);
        inputA->setFont(font);
        inputA->setFocusPolicy(Qt::StrongFocus);
        inputA->setLayoutDirection(Qt::LeftToRight);
        inputA->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        inputD = new QLineEdit(gleichungssystem);
        inputD->setObjectName(QString::fromUtf8("inputD"));
        inputD->setGeometry(QRect(10, 50, 90, 22));
        inputD->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        inputC = new QLineEdit(gleichungssystem);
        inputC->setObjectName(QString::fromUtf8("inputC"));
        inputC->setGeometry(QRect(350, 10, 90, 22));
        inputC->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        inputB = new QLineEdit(gleichungssystem);
        inputB->setObjectName(QString::fromUtf8("inputB"));
        inputB->setGeometry(QRect(180, 10, 90, 22));
        inputB->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        inputE = new QLineEdit(gleichungssystem);
        inputE->setObjectName(QString::fromUtf8("inputE"));
        inputE->setGeometry(QRect(180, 50, 90, 22));
        inputE->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        inputF = new QLineEdit(gleichungssystem);
        inputF->setObjectName(QString::fromUtf8("inputF"));
        inputF->setGeometry(QRect(350, 50, 90, 22));
        inputF->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label34 = new QLabel(gleichungssystem);
        label34->setObjectName(QString::fromUtf8("label34"));
        label34->setGeometry(QRect(290, 50, 30, 20));
        label32 = new QLabel(gleichungssystem);
        label32->setObjectName(QString::fromUtf8("label32"));
        label32->setGeometry(QRect(290, 10, 30, 20));
        label31 = new QLabel(gleichungssystem);
        label31->setObjectName(QString::fromUtf8("label31"));
        label31->setGeometry(QRect(120, 10, 40, 20));
        label33 = new QLabel(gleichungssystem);
        label33->setObjectName(QString::fromUtf8("label33"));
        label33->setGeometry(QRect(120, 50, 30, 20));
        calcButton3 = new QPushButton(gleichungssystem);
        calcButton3->setObjectName(QString::fromUtf8("calcButton3"));
        calcButton3->setGeometry(QRect(220, 140, 114, 32));
        settingsGleichungssystem = new QGroupBox(gleichungssystem);
        settingsGleichungssystem->setObjectName(QString::fromUtf8("settingsGleichungssystem"));
        settingsGleichungssystem->setGeometry(QRect(10, 90, 430, 40));
        checkBox31 = new QCheckBox(settingsGleichungssystem);
        checkBox31->setObjectName(QString::fromUtf8("checkBox31"));
        checkBox31->setGeometry(QRect(10, 10, 220, 20));
        clearButton3 = new QPushButton(gleichungssystem);
        clearButton3->setObjectName(QString::fromUtf8("clearButton3"));
        clearButton3->setGeometry(QRect(330, 140, 114, 32));
        tabs->addTab(gleichungssystem, QString());
        settingsGleichungssystem->raise();
        inputA->raise();
        inputD->raise();
        inputC->raise();
        inputB->raise();
        inputE->raise();
        inputF->raise();
        label34->raise();
        label32->raise();
        label31->raise();
        label33->raise();
        calcButton3->raise();
        clearButton3->raise();
        output = new QTextEdit(centralWidget);
        output->setObjectName(QString::fromUtf8("output"));
        output->setGeometry(QRect(20, 230, 460, 350));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Menlo"));
        font1.setPointSize(12);
        output->setFont(font1);
        Main->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Main);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 500, 22));
        Main->setMenuBar(menuBar);
        statusBar = new QStatusBar(Main);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Main->setStatusBar(statusBar);
        QWidget::setTabOrder(inputIntervall, calcButton1);
        QWidget::setTabOrder(calcButton1, output);
        QWidget::setTabOrder(output, inputFunction);
        QWidget::setTabOrder(inputFunction, calcButton2);
        QWidget::setTabOrder(calcButton2, inputA);
        QWidget::setTabOrder(inputA, inputB);
        QWidget::setTabOrder(inputB, inputC);
        QWidget::setTabOrder(inputC, inputD);
        QWidget::setTabOrder(inputD, inputE);
        QWidget::setTabOrder(inputE, inputF);
        QWidget::setTabOrder(inputF, calcButton3);
        QWidget::setTabOrder(calcButton3, tabs);

        retranslateUi(Main);

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Main);
    } // setupUi

    void retranslateUi(QMainWindow *Main)
    {
        Main->setWindowTitle(QApplication::translate("Main", "Intervallarithmetik", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("Main", "About", 0, QApplication::UnicodeUTF8));
        calcButton1->setText(QApplication::translate("Main", "Calculate", 0, QApplication::UnicodeUTF8));
        labelInput1->setText(QApplication::translate("Main", "Eingabe:", 0, QApplication::UnicodeUTF8));
        settingsRechnen->setTitle(QString());
        clearButton1->setText(QApplication::translate("Main", "Clear", 0, QApplication::UnicodeUTF8));
        tabs->setTabText(tabs->indexOf(rechnen), QApplication::translate("Main", "Grundrechenarten", 0, QApplication::UnicodeUTF8));
        labelInput21->setText(QApplication::translate("Main", "f(x)=", 0, QApplication::UnicodeUTF8));
        calcButton2->setText(QApplication::translate("Main", "Calculate", 0, QApplication::UnicodeUTF8));
        clearButton2->setText(QApplication::translate("Main", "Clear", 0, QApplication::UnicodeUTF8));
        labelInput22->setText(QApplication::translate("Main", "f'(x)=", 0, QApplication::UnicodeUTF8));
        labelInput23->setText(QApplication::translate("Main", "Startintervall:", 0, QApplication::UnicodeUTF8));
        tabs->setTabText(tabs->indexOf(nullstellen), QApplication::translate("Main", "Nullstellen", 0, QApplication::UnicodeUTF8));
        inputA->setText(QString());
        inputA->setPlaceholderText(QApplication::translate("Main", "a", 0, QApplication::UnicodeUTF8));
        inputD->setText(QString());
        inputD->setPlaceholderText(QApplication::translate("Main", "d", 0, QApplication::UnicodeUTF8));
        inputC->setText(QString());
        inputC->setPlaceholderText(QApplication::translate("Main", "c", 0, QApplication::UnicodeUTF8));
        inputB->setInputMask(QString());
        inputB->setText(QString());
        inputB->setPlaceholderText(QApplication::translate("Main", "b", 0, QApplication::UnicodeUTF8));
        inputE->setText(QString());
        inputE->setPlaceholderText(QApplication::translate("Main", "e", 0, QApplication::UnicodeUTF8));
        inputF->setText(QString());
        inputF->setPlaceholderText(QApplication::translate("Main", "f", 0, QApplication::UnicodeUTF8));
        label34->setText(QApplication::translate("Main", "y  =", 0, QApplication::UnicodeUTF8));
        label32->setText(QApplication::translate("Main", "y  =", 0, QApplication::UnicodeUTF8));
        label31->setText(QApplication::translate("Main", "x  +", 0, QApplication::UnicodeUTF8));
        label33->setText(QApplication::translate("Main", "x  +", 0, QApplication::UnicodeUTF8));
        calcButton3->setText(QApplication::translate("Main", "Calculate", 0, QApplication::UnicodeUTF8));
        settingsGleichungssystem->setTitle(QString());
        checkBox31->setText(QApplication::translate("Main", "Ausgabe des Gleichungssytems", 0, QApplication::UnicodeUTF8));
        clearButton3->setText(QApplication::translate("Main", "Clear", 0, QApplication::UnicodeUTF8));
        tabs->setTabText(tabs->indexOf(gleichungssystem), QApplication::translate("Main", "Gleichungssystem", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Main: public Ui_Main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
