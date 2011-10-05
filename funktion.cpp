#include "funktion.h"

const char valid2[] = {'(',')','.','1','2','3','4','5','6','7','8','9','0','x'};
const string binaryFunction[] = {"+","-","*","/","^"};
const string unaryFunction[] = {"exp","sin","cos","sqrt","ln"};

Funktion::Funktion(){
    function = NULL;
}

Funktion::Funktion(binTree* func){
    function = NULL;
    function->insertTree(*&function,func);
}



double Funktion::calculateFunction(double x){
    if(function==NULL)
        return 0;
    if(function->leaf=="" && function->op<sizeof(binaryFunction)/sizeof(binaryFunction[0])){
        Funktion a(function->left);
        Funktion b(function->right);
        switch(function->op){
        case 0:
            return a.calculateFunction(x)+b.calculateFunction(x);
        case 1:
            return a.calculateFunction(x)-b.calculateFunction(x);
        case 2:
            return a.calculateFunction(x)*b.calculateFunction(x);
        case 3:
            return a.calculateFunction(x)/b.calculateFunction(x);
        case 4:
            return pow(a.calculateFunction(x),b.calculateFunction(x));
        }
    }
    if(function->leaf=="" && function->op>=sizeof(binaryFunction)/sizeof(binaryFunction[0])){
        Funktion a(function->left);
        switch(function->op){
        case sizeof(binaryFunction)/sizeof(binaryFunction[0]):
            return exp(a.calculateFunction(x));
        case sizeof(binaryFunction)/sizeof(binaryFunction[0])+1:
            return sin(a.calculateFunction(x));
        case sizeof(binaryFunction)/sizeof(binaryFunction[0])+2:
            return cos(a.calculateFunction(x));
        case sizeof(binaryFunction)/sizeof(binaryFunction[0])+3:
            return sqrt(a.calculateFunction(x));
        case sizeof(binaryFunction)/sizeof(binaryFunction[0])+4:
            return log(a.calculateFunction(x));
        }
    }
    if(function->leaf=="x")
        return x;
    return parseNumbers(function->leaf);
}

binTree* Funktion::getFunction(){
    return function;
}

bool Funktion::validChars(string input){
    //Ungueltige Zeichen finden
    for(int j=0;j<input.length();j++){
        bool val=0;
        for(int i=0;i<sizeof(valid2)/sizeof(valid2[0]);i++){
            if(input[j]==valid2[i])
                val=1;
        }
        for(int i=0;i<sizeof(binaryFunction)/sizeof(binaryFunction[0]);i++){
            if(input.substr(j,binaryFunction[i].length())==binaryFunction[i]){
                val = 1;
                j += binaryFunction[i].length()-1;
            }
        }
        for(int i=0;i<sizeof(unaryFunction)/sizeof(unaryFunction[0]);i++){
            if(input.substr(j,unaryFunction[i].length())==unaryFunction[i]){
                val = 1;
                j += unaryFunction[i].length()-1;
            }
        }
        if(val==0)
            return false;
    }
  return true;
}

string Funktion::multiplicationSign(string input){
    string::iterator it;
    for(it=input.begin();it<=input.end();it++){
        if(*it=='x'){
            if(*(it-1)>='0' && *(it-1)<='9'){
                it = input.insert(it,'*');
                it++;
            }
            if(*(it+1)>='0' && *(it+1)<='9'){
                it = input.insert(it+1,'*');
            }
        }
    }
    return input;
}

int Funktion::parseFunction(string func){
    string::iterator it;
    func = clearString(func);
    func = multiplicationSign(func);
    if(func=="")
        return 0;
    if(brackets(func)==false){
        return 1;
    }
    if(Funktion::validChars(func)==false){
        return 2;
    }
    int brackets = 0;
    for(int i=0;i<2;i++){
        for(it=func.end();it>=func.begin();it--){
            if(*it=='(')
                brackets--;
            if(*it==')')
                brackets++;
            if(*it==binaryFunction[i].at(0) && brackets==0 && *(it-1)!='/' && *(it-1)!='*' && *(it-1)!='-' && *(it-1)!='+'){
                Funktion a;
                Funktion b;
                if(it==func.begin()){
                    string funca(it+1,func.end());
                    int retVal = a.parseFunction(funca);
                    if(retVal==0){
                        function->insert(function,i,"");
                        function->insertTree(function->right,a.getFunction());
                    }
                    return retVal;
                }
                else if(it==func.end()){
                    return 3;
                }
                else{
                    string funca(func.begin(),it);
                    string funcb(it+1,func.end());
                    int retVal1 = a.parseFunction(funca);
                    int retVal2 = b.parseFunction(funcb);
                    if(retVal1==0 && retVal2==0){
                        function->insert(function,i,"");
                        function->insertTree(function->left,a.getFunction());
                        function->insertTree(function->right,b.getFunction());
                        return 0;
                    }
                    if(retVal1==0)
                        return retVal2;
                    if(retVal2==0)
                        return retVal1;
                    return -1;
                }
            }
        }
    }
    for(int i=2;i<sizeof(binaryFunction)/sizeof(binaryFunction[0]);i++){
        for(it=func.end();it>=func.begin();it--){
            if(*it=='(')
                brackets--;
            if(*it==')')
                brackets++;
            if(*it==binaryFunction[i].at(0) && brackets==0){
                Funktion a;
                Funktion b;
                if(it==func.begin()){
                    return 3;
                }
                else if(it==func.end()){
                    return 3;
                }
                else{
                    string funca(func.begin(),it);
                    string funcb(it+1,func.end());
                    int retVal1 = a.parseFunction(funca);
                    int retVal2 = b.parseFunction(funcb);
                    if(retVal1==0 && retVal2==0){
                        function->insert(function,i,"");
                        function->insertTree(function->left,a.getFunction());
                        function->insertTree(function->right,b.getFunction());
                        return 0;
                    }
                    if(retVal1==0)
                        return retVal2;
                    if(retVal2==0)
                        return retVal1;
                    return -1;
                }
            }
        }
    }
    it = func.begin();
    for(int i=0;i<sizeof(unaryFunction)/sizeof(unaryFunction[0]);i++){
        if(string(it,it+unaryFunction[i].length())==unaryFunction[i] && brackets==0){
            Funktion a;
            string funca(func,unaryFunction[i].length());
            int retVal = a.parseFunction(funca);
            if(retVal==0){
                function->insert(function,i+sizeof(binaryFunction)/sizeof(binaryFunction[0]),"");
                function->insertTree(function->left,a.getFunction());
            }
            return retVal;
        }
    }
    if(*it=='('){
        Funktion a;
        string funca(func.begin()+1,func.end()-1);
        int retVal = a.parseFunction(funca);
        if(retVal==0)
            function->insertTree(function,a.getFunction());
        return retVal;
    }
    if(*it=='x'){
        function->insert(function,-4,"x");
        return 0;
    }
    function->insert(function,-3,func);
    return 0;
}

Intervall Funktion::fInt(Intervall x, double acc=.001){
    double inf = calculateFunction(x.getSup());
    double sup = calculateFunction(x.getSup());
    for(double i=x.getInf();i<x.getSup();i+=acc){
        if(calculateFunction(i)<inf)
            inf = calculateFunction(i);
        else if(calculateFunction(i)>sup)
            sup = calculateFunction(i);
    }
    return Intervall(inf,sup);
}

double Funktion::newtonIntervall(Intervall searchRootHere, Funktion derivate){
    Intervall x(searchRootHere.getInf(),searchRootHere.getSup());
    while(x.getInf()!=x.getSup()){
        x = (x.x_()-calculateFunction(x.x_())/derivate.fInt(x))&&x;
        if(x.getInf()!=x.getInf())
            return NAN;
    }
    return x.getInf();
}
