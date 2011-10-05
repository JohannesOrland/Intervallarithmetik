#ifndef GUI_H
#define GUI_H

#include <QMainWindow>
#include <QtGui>
#include <QShortcut>
#include <sstream>
#include <math.h>
#include "ui_gui.h"
#include "parser.h"
#include "intervall.h"
#include "funktion.h"

using namespace std;

/*! GUI-Klasse.
*/
class gui : public QMainWindow, public Ui::Main {
    Q_OBJECT
private:
    /*! Shortcut für clearOutput().
    */
    QShortcut * clearOutputSc;
    /*! Shortcut für clearInput().
    */
    QShortcut * clearInputSc;
    /*! Shortcut für calculate().
    */
    QShortcut * calcSc;
public:
    /*! GUI-Konstruktor.
      Ruft den Konstruktor der grafischen Oberfläche auf.
    */
    gui(QMainWindow *parent = 0);
    /*! GUI-Desktruktor.
      Ruft den Desktruktor der grafischen Oberfläche auf.
    */
    ~gui();

public Q_SLOTS:

private Q_SLOTS:
    /*! Gibt verarbeitete Intervalleingaben aus.
    */
    void calculateIntervall();
    /*! Gibt verabeitete Gleichungssystemeingaben aus.
    */
    void calculateLgs();
    /*! Gibt verarbeitete Funktionseingaben aus.
    */
    void calculateFunction();
    /*! Löscht Ausgabefeld und reinitialisiert output.
    */
    void clearOutput();
    /*! Löscht Inputfelder.
      Löscht Inputfelder abhängig vom aktiven Tab.
    */
    void clearInput();
    //void switchPlotOutput();
    /*! Verbindet den Shortcut calcSc mit den jeweiligen Funktionen abhängig von aktiven Tab.
    */
    void calcShortcut();
};
/*! Fehlermeldung.
  Gibt Fehlermeldung mit Fehlertext str als Popup aus.
*/
void errorWindow(string str);
/*! Infofenster.
  Gibt ein Infofenster aus.
*/
void infoWindow();

#endif // GUI_H
