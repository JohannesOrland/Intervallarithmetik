#ifndef INTERVALL_H
#define INTERVALL_H

#include <iostream>
#include <string.h>
#include <sstream>
#include <math.h>
#include "hilfsfunktionen.h"

using namespace std;

/*! Intervallklasse.
  Ermöglicht Intervallrechnung.
*/
class Intervall {
    private:
        /*! Untere Grenze des Intervalls.
        */
        double inf;
        /*! Obere Grenze des Intervalls.
        */
        double sup;
    public:
        /*! Standard-Intervall-Konstruktor.
          Erstellt eine Intervallinstanz mit unterer und oberer Grenze.
        */
        Intervall(double inf1,double sup1);
        /*! Intervall-Konstruktor (überladen).
          Erstellt eine Intervallinstanz mit gleicher unterer und oberer Grenze.
        */
        Intervall(double infsup);
        /*! Intervall-Destruktor.
        */
        ~Intervall(){}
        /*! Setterfunktion.
        */
        void setIntervall(double inf, double sup);
        /*! Gibt die untere Grenze des Intervalls aus.
        */
        double getInf(){return inf;}
        /*! Gibt die obere Grenze des Intervalls aus.
        */
        double getSup(){return sup;}
        /*! Wandelt das Intervall in einen String um.
        */
        string printToString();
        /*! Gibt den Durchmesser des Intervalls aus.
        */
        double d();
        /*! Gibt den Mittelpunkt des Intervalls aus.
        */
        double x_();
        /*! + (überladen).
          Intervalladdition.
        */
        friend Intervall operator+(Intervall a, Intervall b);
        /*! - (überladen).
          Intervallsubtraktion.
        */
        friend Intervall operator-(Intervall a, Intervall b);
        /*! * (überladen).
          Intervallmultiplikation.
        */
        friend Intervall operator*(Intervall a, Intervall b);
        /*! / (überladen).
          Intervalldivision.
        */
        friend Intervall operator/(Intervall a, Intervall b);
        /*! &&(überladen).
          Durchschnitt von Intervallen.
        */
        friend Intervall operator&&(Intervall a, Intervall b);
        /*! ||(überladen).
          Vereinigung von Intervallen.
        */
        friend Intervall operator||(Intervall a, Intervall b);
        /*! Wertet eine übergebene Funktion auf dem Intervall numerisch aus.
        */
        Intervall fInt(double (*f)(double), Intervall x, double acc);
        /*! Berechnet eine Nullstelle einer übergebenen Funktion in dem Intervall.
        */
        double newtonIntervall(double (*f)(double), double (*f1)(double));
};

#endif // INTERVALL_H
