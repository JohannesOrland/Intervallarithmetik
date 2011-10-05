#ifndef PARSER_H
#define PARSER_H
#include <string.h>
#include <math.h>
#include <iostream>
#include "intervall.h"
#include "gui.h"
/*! \file parser.h*/
using namespace std;
/*! Array aller gültigen Zeichen für die Intervalleingabe.
*/
const char valid[]={'[',']','(',')',',','.','1','2','3','4','5','6','7','8','9','0','+','-','*','/','&','|'};
/*! Löscht die Leerzeichen eines Strings.
*/
string clearString(string input);
/*! Überprüft den String auf ungültige Zeichen
*/
bool validChars(string input);
/*!
  Überprüft, ob die Anzahl der öffnenden und schliessenden runden Klammern übereinstimmt.
*/
bool brackets(string input);
/*!
  Überprüft, ob die Anzahl der öffnenden und schliessenden eckigen Klammern übereinstimmt.
*/
bool intervalBrackets(string input);
/*! Konvertiert einen String in eine Zahl
*/
double parseNumbers(string input);
/*! Konvertiert einen String in ein Intervall
*/
Intervall parseIntervals(string input);
/*! Konvertiert einen String in eine Verknüpfung von Zahlen
*/
double parseTermOfNumbers(string input);
/*! Konvertiert einen String in eine Verknüpfung von Intervallen.
*/
Intervall parseTermOfIntervals(string input);
/*! Uberprüft und konvertiert einen String in eine Verknüpfung von Intervallen und Zahlen.
*/
Intervall parse(string input);

#endif // PARSER_H
