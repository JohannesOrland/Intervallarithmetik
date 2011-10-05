#ifndef FUNKTION_H
#define FUNKTION_H

#include <iostream>
#include <string.h>
#include <sstream>
#include <math.h>
#include "parser.h"
#include "gui.h"

using namespace std;


/*! Struktur Binärbaum
*/

struct binTree{
    /*! Operator, mit dem die beiden Teilfunktionen verknüpft sind
    */
    int op;
    /*! Inhalt eines Blattes
        Kann x oder Zahl enthalten. Bei inneren Knoten der leere String.
    */
    string leaf;
    /*! Linker Teilbaum beziehungsweise linke Teilfunktion.
    */
    binTree *left;
    /*! Rechter Teilbaum beziehungsweise rechte Teilfunktion.
    */
    binTree *right;

    /*! Konstruktor
        Erstellt aus einem Operator und dem möglichen Blattinhalt einen Knoten.
    */
    binTree(int o,string le){
        op = o;
        leaf = le;
        left = NULL;
        right = NULL;
    }
    /*! Fügt einen Knoten an Stelle des angegebenen leeren Knotens ein.
    */
    void insert(binTree *&root, int o, string le){
        if(root==NULL){
            root = new binTree(o,le);
        }
    }
    /*! Fügt einen Baum an Stelle des angegebenen leeren Knotens ein.
    */
    void insertTree(binTree *&root, binTree *toInsert){
        if(root==NULL){
            if(toInsert!=NULL){
                insert(root,toInsert->op,toInsert->leaf);
                insertTree(root->left,toInsert->left);
                insertTree(root->right,toInsert->right);
            }
        }
    }
};

/*! Funktionenklasse
    Kann aus Strings eingelesene Funktionen in einem Binärbaum speichern.
*/

class Funktion
{
private:
    /*! Der Binärbaum, der die Funktion speichert.
    */
    binTree* function;
public:
    /*! Standarkonstruktor
    */
    Funktion();
    /*! Konstruktor, der eine Funktion aus einem bestehenden Binärbaum erstellt.
    */
    Funktion(binTree* func);
    /*! Berechnet den Funktionswert an der Stelle x.
    */
    double calculateFunction(double x);
    /*! Bestimmt numerisch das Intervall, aus das die Funktion ein gegebenes Intervall abbildet.
    */
    Intervall fInt(Intervall x,double acc);
    /*! Gibt den Binärbaum aus.
    */
    binTree* getFunction();
    /*! Überprüft einen String auf für die Funktionseingabe ungültige Zeichen und Zeichenketten.
    */
    bool validChars(string input);
    /*! Fügt in den String weggelassene Multiplikationszeichen ein.
    */
    string multiplicationSign(string input);
    /*! Liest den String ein.
    */
    int parseFunction(string func);
    /*! Berechnet mit einem geeigneten Intervall und der Ableitung eine Nullstelle der Funktion.
    */
    double newtonIntervall(Intervall searchRootHere, Funktion derivate);
};

#endif // FUNKTION_H
