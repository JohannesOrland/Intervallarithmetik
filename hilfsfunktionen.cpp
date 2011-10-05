#include "hilfsfunktionen.h"

double max(double a, double b){
    if(a >= b){
        return a;
    } else {
        return b;
    }
}

double min(double a, double b){
    if(a >= b){
        return b;
    } else {
        return a;
    }
}

double max4(double a, double b, double c, double d){
    return max(a, max(b, max(c, d)));
}

double min4(double a, double b, double c, double d){
    return min(a, min(b, min(c, d)));
}
