#include <QApplication>
#include "intervall.h"
#include "gui.h"
#include "parser.h"
/*! \mainpage Programm zur Intervallarithmetik
  \section Anleitung
  \subsection Rechenoperationen
  Zum Rechnen mit Intervallen stehen Addition <b>+</b>, Subtraktion <b>-</b>, Multipliaktion <b>*</b>,
  Division <b>/</b>, Vereinigung <b>|</b> und Durchschnitt <b>&</b> zur Verfügung.
  \image html prog_abb_1.jpg
  \subsection Intervallrechnung
  Ein Intervall wird als <em>[a,b]</em> eingegeben, wobei <i>a</i> die untere und <i>b</i> die obere
  Intervallgrenze darstellt. <i>a</i> und <i>b</i> dürfen sowohl reelle Zahlen als auch Verküpfungen
  von reellen Zahlen durch <b>+</b>, <b>-</b>, <b>*</b> und <b>/</b> miteinander sein. Außerdem dürfen
  die Prioritäten der Rechenoperationen auch durch runde Klammern <b>(</b> und <b>)</b> geändert werden.
  Ein Punktintervall wird entweder als <em>[a]</em> oder als <em>a</em> eingegeben.
  \subsection Nullstellenberechnung
  \image html prog_abb_2.jpg
  Zur Nullstellenberechnung muss die Funktion deren Nullstelle bestimmt werden soll, in das erste Eingabefeld
  <em>f(x)</em> eingegeben werden. In das zweite Feld <em>f'(x)</em> wird die Ableitung der Funktion eingetragen.
  Anschliessend muss in das Eigabefeld <em>Start</em> ein Startintervall eingegeben werden.
  \subsection Gleichungssystem
  \image html prog_abb_3.jpg
  In die Felder müssen die Koeffizienten der Gleichung eingetragen werden. Diese können Zahlen, Verknüpfungen
  von Zahlen, Intervalle und Verknüpfungen von Intervallen sein.
  \subsection Einschränkungen
  \subsubsection Grundrechenarten
  \subsubsection Nullstellen
  Es findet keine Überprüfung auf Extremstellen statt. Liegt die Nullstelle an einer Extremstelle kann das
  verwendete Newton-Intervallvervahren keine Lösung finden.
  \subsubsection Gleichungssystem
  \subsection Theoretische Grundlagen

Im folgenden sind wenn von Intervallen gesprochen wird, immer reelle, abgeschlossene Intervalle gemeint. Zwar lassen sich die Verknüpfungsregeln auch auf allgemeine, reelle Intervalle erweitern, da unser Programm aber nur mit abgeschlossenen Intervallen arbeitet, wird darauf nicht näher eingegangen.

Intervalle können mit den gleichen Operatoren verknüpft werden, wie gewöhnliche Zahlen. Für die einzelnen Operatoren gibt es explizite Regeln. Allerdings folgen diese Regeln alle einer grundlegenden Regel. Das Intervall, dass sich aus der Verknüpfung von zwei Intervallen ergibt, ist das Intervall, welches alle Zahlen enthält, die das Ergebnis einer Verknüpfung aus zwei Zahlen aus den beiden Intervallen sein können.

Also kann die Addition zweier Intervall folgendermaßen definiert werden:

[a,b]+[r,s]:={x|x=c+t,c aus [a,b],t aus [r,s]}

Die Intervallvarianten der Addition, Substrakt, Multiplikation und Division hängen nur vom Infimum und Supremum der verknüpften Intervalle ab. Es lassen sich folgende explizite Regeln angeben:

[a,b]+[c,d]=[a+c,b+d]\n
[a,b]-[c,d]=[a-d,b-c]\n
[a,b]*[c,d]=[min(a*c,a*d,b*c.b*d),max(a*c,a*d,b*c.b*d)]\n
[a,b]/[c,d]=[min(a/c,a/d,b/c.b/d),max(a/c,a/d,b/c.b/d)]\n

Für die Division muss für diese Regel vorausgesetzt sein, dass das Intervall durch das geteilt wird die Null nicht enthält. Eine Division durch ein Intervall, dass die Null enthält, zu definieren ist möglich, wenn man als Intervallgrenzen unendlich und minus unendlich zulässt. Da in unserer Klasse diese Operation aber nicht implementiert ist wird hier nicht näher darauf eingegangen.

Ein Intervall dessen Ober- und Untergrenze ¸bereinstimmen wird Punktintervall genannt. Wie sich an den Rechenregeln erkennen lässt, verhalten sich die reellen Punktintervalle genauso wie die reellen Zahlen.


\subsubsection Das Newton-Intervall Verfahren

Das Newton-Intervall Verfahren bestimmt Nullstellen einer Funktion. Es ist ein leicht abgeändertes Newton Verfahren, bei dem die Konvergenz sicher gestellt ist. Dass heißt, es kann nicht passieren, dass das Verfahren zu keinem Ergebnis kommt. Wenn sich im Intervall keine Nullstelle befindet wird auch das erkannt.

Das Verfahren verkleinert das Intervall in dem die Nullstelle liegt, bis es sich um ein Punktintervall handelt. Dazu wird folgende Iterationsregel angewandt:

[k+1] = (x - f(x)/f'([k])) | [k]

Bezeichnungen: 	[k], das Intervall der k-ten Iteration\n
                x, ein Element aus [k]\n
                |, Schnitt zweier Intervalle\n

Durch das Schneiden mit dem Intervall wird sicher gestellt, dass das Intervall sich nicht wieder vergrößert. Wenn sich in dem Intervall keine Nullstelle befindet ist das Intervall nach endlich vielen Schritten leer.
Wie an der Regel zu erkennen, darf f' im Intervall keine Nullstelle besitzen, da sonst durch ein Null enthaltendes Intervall geteilt werden müsste.

\subsection Literaturangaben

-Grundbegriffe der Intervallrechnung, G. Mayer
-Lineare Probleme, S. M. Rump
*/
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gui w;
    w.show();
    return a.exec();
}
