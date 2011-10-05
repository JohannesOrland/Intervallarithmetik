#include "intervall.h"

Intervall::Intervall(double inf1, double sup1):inf(inf1), sup(sup1){
    if(inf > sup){
        double tmp;
        tmp=inf;
        inf=sup;
        sup=tmp;
    }
}

Intervall::Intervall(double infsup){
    inf=infsup;
    sup=infsup;
}

string Intervall::printToString(){
    stringstream numbers;
    string interval = "[,]";
    numbers << inf;
    if(inf==sup)
        return numbers.str();
    interval.insert(1,numbers.str());
    numbers.str("");
    numbers << sup;
    interval.insert(interval.length()-1,numbers.str());
    return interval;
}

void Intervall::setIntervall(double inf1, double sup1){
    inf=inf1;
    sup=sup1;
}

double Intervall::d(){
    return (sup-inf);
}

double Intervall::x_(){
    return (inf+sup)/2;
}

Intervall operator+(Intervall a, Intervall b){
    return Intervall(a.inf+b.inf,a.sup+b.sup);
}

Intervall operator-(Intervall a, Intervall b){
    return Intervall(a.inf-b.sup,a.sup-b.inf);
}

Intervall operator*(Intervall a, Intervall b){
    return Intervall(min4(a.inf*b.inf,a.inf*b.sup,a.sup*b.inf,a.sup*b.sup),max4(a.inf*b.inf,a.inf*b.sup,a.sup*b.inf,a.sup*b.sup));
}

Intervall operator/(Intervall a, Intervall b){
    if(b.inf<=0 and b.sup>=0){
        return Intervall(NAN);
    } else{
        return a*Intervall(1/b.sup,1/b.inf);
    }
}

Intervall operator&&(Intervall a, Intervall b){
    if(max(a.inf,b.inf) <= min(a.sup,b.sup)){
        return Intervall(max(a.inf,b.inf),min(a.sup,b.sup));
    } else {
        return Intervall(NAN);
    }
}

Intervall operator||(Intervall a, Intervall b){
    if(min(a.sup,b.sup)>=max(a.inf,b.inf))
        return Intervall(min(a.inf,b.inf),max(a.sup,b.sup));
    else
        return Intervall(NAN);
}

Intervall Intervall::fInt(double (*f)(double), Intervall x, double acc=.001){
    double inf = (*f)(x.getSup());
    double sup = (*f)(x.getSup());
    for(double i=x.getInf();i<x.getSup();i+=acc){
        if((*f)(i)<inf)
            inf = (*f)(i);
        else if((*f)(i)>sup)
            sup = (*f)(i);
    }
    return Intervall(inf,sup);
}

double Intervall::newtonIntervall(double (*f)(double), double (*f1)(double)){
    Intervall x(inf,sup);
    while(x.getInf()!=x.getSup()){
        x = (x.x_()-(*f)(x.x_())/fInt((*f1),x))&&x;
        if(x.getInf()!=x.getInf())
            return NAN;
    }
    return x.getInf();
}
