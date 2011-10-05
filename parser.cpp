#include "parser.h"

string clearString(string input){
    //Leerzeichen loeschen
    for(size_t space=input.find(" ");input.find(" ")!=string::npos; space=input.find(" ")){
        input=input.erase(space, 1);
    }
    return input;
}

bool validChars(string input){
    //Ungueltige Zeichen finden
    for(int j=0;j<input.length();j++){
        bool val=0;
        for(int i=0;i<22;i++){
            if(input[j]==valid[i])
                val=1;
        }
        if(val==0)
            return false;
    }
  return true;
}

bool brackets(string input){
    string::iterator it;
    int brackets = 0;
    for(it=input.begin();it<input.end();it++){
        if(*it=='(')
            brackets++;
        if(*it==')')
            brackets--;
        if(brackets<0)
            return false;
    }
    if(brackets!=0){
        return false;
    }
    return true;
}

bool intervalBrackets(string input){
    string::iterator it;
    int brackets = 0;
    for(it=input.begin();it<input.end();it++){
        if(*it=='[')
            brackets++;
        if(*it==']')
            brackets--;
        if(brackets<0)
            return false;
        if(brackets>1)
            return false;
    }
    if(brackets!=0)
        return false;
    return true;
}

double parseNumbers(string input){
    string::iterator it;
    it = input.begin();
    double result=0;
    while(*it>='0' && *it<='9'){
        switch(*it){
            case '0':
                result *= 10;
                break;
            case '1':
                result *= 10;
                result += 1;
                break;
            case '2':
                result *= 10;
                result += 2;
                break;
            case '3':
                result *= 10;
                result += 3;
                break;
            case '4':
                result *= 10;
                result += 4;
                break;
            case '5':
                result *= 10;
                result += 5;
                break;
            case '6':
                result *= 10;
                result += 6;
                break;
            case '7':
                result *= 10;
                result += 7;
                break;
            case '8':
                result *= 10;
                result += 8;
                break;
            case '9':
                result *= 10;
                result += 9;
                break;
        }
        it++;
    }
    if(*it=='.'){
        it++;
        int stelle = -1;
        while(*it>='0' && *it<='9'){
            switch(*it){
                case '0':
                    break;
                case '1':
                    result += 1*pow(10,stelle);
                    break;
                case '2':
                    result += 2*pow(10,stelle);
                    break;
                case '3':
                    result += 3*pow(10,stelle);
                    break;
                case '4':
                    result += 4*pow(10,stelle);
                    break;
                case '5':
                    result += 5*pow(10,stelle);
                    break;
                case '6':
                    result += 6*pow(10,stelle);
                    break;
                case '7':
                    result += 7*pow(10,stelle);
                    break;
                case '8':
                    result += 8*pow(10,stelle);
                    break;
                case '9':
                    result += 9*pow(10,stelle);
                    break;
            }
            it++;
            stelle--;
        }
    }
    if(it!=input.end()){
        errorWindow("Couldn't read Number");
        return NAN;
    }
    return result;
}

Intervall parseIntervals(string input){
    size_t found = input.find_first_of(',');
    if(found==string::npos){
        string input1 = input.substr(1,input.length()-2);
        double infNumber = parseTermOfNumbers(input1);
        QString inf = inf.number(infNumber);
        if(inf!="nan"){
            return Intervall(infNumber);
        }
        return Intervall(NAN);
    }
    string input2 = input.substr(1,found-1);
    string input3 = input.substr(found+1,input.length()-found-2);
    double infNumber = parseTermOfNumbers(input2);
    QString inf = inf.number(infNumber);
    double supNumber = parseTermOfNumbers(input3);
    QString sup = sup.number(supNumber);
    if(inf!="nan" && sup!="nan"){
        return Intervall(infNumber,supNumber);
    }
    return  Intervall(NAN);
}

double parseTermOfNumbers(string input){
    string::iterator it;
    int brackets = 0;
    if(input=="")
        return 0;
    for(it=input.end();it>=input.begin();it--){
        if(*it=='(')
            brackets++;
        if(*it==')')
            brackets--;
        if(*it=='+' && brackets==0 && *(it-1)!='/' && *(it-1)!='*' && *(it-1)!='-' && *(it-1)!='+' && *(it-1)!='|' && *(it-1)!='&'){
            if(it==input.begin()){
                string input2(it+1,input.end());
                return parseTermOfNumbers(input2);
            }
            if(it+1==input.end()){
                //Bin‰rem Operator fehlt Operand//
                errorWindow("Operand missing!");
                return double(NAN);
            }
            string input1(input.begin(),it);
            string input2(it+1,input.end());
            return parseTermOfNumbers(input1)+parseTermOfNumbers(input2);
        }
        if(*it=='-' && brackets==0 && *(it-1)!='/' && *(it-1)!='*' && *(it-1)!='-' && *(it-1)!='+' && *(it-1)!='|' && *(it-1)!='&'){
            if(it==input.begin()){
                string input2(it+1,input.end());
                return -parseTermOfNumbers(input2);
            }
            if(it+1==input.end()){
                //Bin‰rem Operator fehlt Operand//
                errorWindow("Operand missing!");
                return double(NAN);
            }
            string input1(input.begin(),it);
            string input2(it+1,input.end());
            return parseTermOfNumbers(input1)-parseTermOfNumbers(input2);
        }
    }
    it=input.begin();
    if(*it=='('){
        brackets++;
        while(brackets>0){
            it++;
            if(*it=='(')
                brackets++;
            if(*it==')')
                brackets--;
        }
        it++;
        if(it==input.end()){
            string input1(input.begin()+1,input.end()-1);
            return parseTermOfNumbers(input1);
        }
        if(*it=='*'){
            string input1(input.begin()+1,it-1);
            if(it+1==input.end()){
                //Bin‰rem Operator fehlt Operand//
                errorWindow("Operand missing!");
                return double(NAN);
            }
            string input2(it+1,input.end());
            return parseTermOfNumbers(input1)*parseTermOfNumbers(input2);
        }
        if(*it=='/'){
            string input1(input.begin()+1,it-1);
            if(it+1==input.end()){
                //Bin‰rem Operator fehlt Operand//
                errorWindow("Operand missing!");
                return double(NAN);
            }
            string input2(it+1,input.end());
            double result2 = parseTermOfNumbers(input2);
            if(result2==0){
                //Teilen durch 0!
                errorWindow("Division by zero!");
                return double(NAN);
            }
            return parseTermOfNumbers(input1)/result2;
        }
    }
    if(*it=='*' || *it=='/'){
        //Bin‰rem Operator fehlt Operand//
        errorWindow("Operand missing!");
        return double(NAN);
    }
    size_t found1 = input.find_first_of("*");
    if(found1!=string::npos){
        string input1 = input.substr(0,found1);
        string input2 = input.substr(found1+1);
        return parseNumbers(input1)*parseTermOfNumbers(input2);
    }
    size_t found2 = input.find_first_of("/");
    if(found2!=string::npos){
        string input1 = input.substr(0,found2);
        string input2 = input.substr(found2+1);
        double result2 = parseTermOfNumbers(input2);
        if(result2==0){
            //Teilen durch 0!
            errorWindow("Division by zero!");
            return double(NAN);
        }
        return parseNumbers(input1)/result2;
    }
    if(found1==string::npos && found2==string::npos){
        return parseNumbers(input);
    }
    errorWindow("42!");
    return double(NAN);
}

Intervall parseTermOfIntervals(string input){
    string::iterator it;
    int brackets = 0;
    int closedBrackets = 0;
    if(input=="")
        return 0;
    for(it=input.end();it>=input.begin();it--){
        if(*it=='(')
            brackets++;
        if(*it==')')
            brackets--;
        if(*it=='[')
            closedBrackets++;
        if(*it==']')
            closedBrackets--;
        if(*it=='|' && brackets==0 && closedBrackets==0){
            if(it==input.begin()){
                //Bin‰rem Operator fehlt Operand
                errorWindow("Operand missing!");
                return Intervall(NAN);
            }
            if(it+1==input.end()){
                //Bin‰rem Operator fehlt Operand
                errorWindow("Operand missing!");
                return Intervall(NAN);
            }
            string input1(input.begin(),it);
            string input2(it+1,input.end());
            Intervall result = parseTermOfIntervals(input1)||parseTermOfIntervals(input2);
            if(result.getInf()!=result.getInf()){
                errorWindow("Vereinigung disjunkter Intervalle!");
            }
            return result;
        }
    }
    for(it=input.end();it>=input.begin();it--){
        if(*it=='(')
            brackets++;
        if(*it==')')
            brackets--;
        if(*it=='[')
            closedBrackets++;
        if(*it==']')
            closedBrackets--;
        if(*it=='&' && brackets==0 && closedBrackets==0){
            if(it==input.begin()){
                //Bin‰rem Operator fehlt Operand
                errorWindow("Operand missing!");
                return Intervall(NAN);
            }
            if(it+1==input.end()){
                //Bin‰rem Operator fehlt Operand
                errorWindow("Operand missing!");
                return Intervall(NAN);
            }
            string input1(input.begin(),it);
            string input2(it+1,input.end());
            Intervall result = parseTermOfIntervals(input1)&&parseTermOfIntervals(input2);
            if(result.getInf()!=result.getInf()){
                errorWindow("Schnitt disjunkter Intervalle!");
            }
            return result;
        }
    }
    for(it=input.end();it>=input.begin();it--){
        if(*it=='(')
            brackets++;
        if(*it==')')
            brackets--;
        if(*it=='[')
            closedBrackets++;
        if(*it==']')
            closedBrackets--;
        if(*it=='+' && brackets==0 && closedBrackets==0 && *(it-1)!='/' && *(it-1)!='*' && *(it-1)!='-' && *(it-1)!='+'){
            if(it==input.begin()){
                string input2(it+1,input.end());
                return parseTermOfIntervals(input2);
            }
            if(it+1==input.end()){
                //Bin‰rem Operator fehlt Operand//
                errorWindow("Operand missing!");
                return Intervall(NAN);
            }
            string input1(input.begin(),it);
            string input2(it+1,input.end());
            return parseTermOfIntervals(input1)+parseTermOfIntervals(input2);
        }
        if(*it=='-' && brackets==0 && closedBrackets==0 && *(it-1)!='/' && *(it-1)!='*' && *(it-1)!='-' && *(it-1)!='+'){
            if(it==input.begin()){
                string input2(it+1,input.end());
                return Intervall(0)-parseTermOfIntervals(input2);
            }
            if(it+1==input.end()){
                //Bin‰rem Operator fehlt Operand//
                errorWindow("Operand missing!");
                return Intervall(NAN);
            }
            string input1(input.begin(),it);
            string input2(it+1,input.end());
            return parseTermOfIntervals(input1)-parseTermOfIntervals(input2);
        }
    }
    it=input.begin();
    if(*it=='('){
        brackets++;
        while(brackets>0){
            it++;
            if(*it=='(')
                brackets++;
            if(*it==')')
                brackets--;
        }
        it++;
        if(it==input.end()){
            string input1(input.begin()+1,input.end()-1);
            return parseTermOfIntervals(input1);
        }
        if(*it=='*'){
            string input1(input.begin()+1,it-1);
            if(it+1==input.end()){
                //Bin‰rem Operator fehlt Operand//
                errorWindow("Operand missing!");
                return Intervall(NAN);
            }
            string input2(it+1,input.end());
            return parseTermOfIntervals(input1)*parseTermOfIntervals(input2);
        }
        if(*it=='/'){
            string input1(input.begin()+1,it-1);
            if(it+1==input.end()){
                //Bin‰rem Operator fehlt Operand//
                errorWindow("Operand missing!");
                return Intervall(NAN);
            }
            string input2(it+1,input.end());
            Intervall result2 = parseTermOfIntervals(input2);
            if(result2.getInf()<=0 && result2.getSup()>=0){
                //Teilen durch 0!
                errorWindow("Division by zero!");
                return Intervall(NAN);
            }
            return parseTermOfIntervals(input1)/result2;
        }
    }
    if(*it=='*' || *it=='/'){
        //Bin‰rem Operator fehlt Operand//
        errorWindow("Operand missing!");
        return Intervall(NAN);
    }
    closedBrackets = 0;
    if(*it=='['){
        for(;it<input.end();it++){
            if(*it=='[')
                closedBrackets++;
            if(*it==']')
                closedBrackets--;
            if(*it=='*' && closedBrackets==0){
                string input1(input.begin(),it);
                string input2(it+1,input.end());
                return parseIntervals(input1)*parseTermOfIntervals(input2);
            }
            if(*it=='/' && closedBrackets==0){
                string input1(input.begin(),it);
                string input2(it+1,input.end());
                Intervall result2 = parseTermOfIntervals(input2);
                if(result2.getInf()<=0 && result2.getSup()>=0){
                    //Teilen durch 0!
                    errorWindow("Division by zero!");
                    return Intervall(NAN);
                }
                return parseIntervals(input1)/result2;
            }
        }
        return parseIntervals(input);
    }
    size_t found1 = input.find_first_of("*");
    if(found1!=string::npos){
        string input1 = input.substr(0,found1);
        string input2 = input.substr(found1+1);
        return parseNumbers(input1)*parseTermOfIntervals(input2);
    }
    size_t found2 = input.find_first_of("/");
    if(found2!=string::npos){
        string input1 = input.substr(0,found2);
        string input2 = input.substr(found2+1);
        Intervall result2 = parseTermOfIntervals(input2);
        if(result2.getInf()<=0 && result2.getSup()>=0){
            //Teilen durch 0!
            errorWindow("Division by zero!");
            return Intervall(NAN);
        }
        return parseNumbers(input1)/result2;
    }
    if(found1==string::npos && found2==string::npos){
        return parseNumbers(input);
    }

    errorWindow("42: "+input);
    return Intervall(NAN);
}

Intervall parse(string input){
    Intervall result = Intervall(NAN);
    //string term((inputIntervall->text()).toStdString());
    string term=clearString(input);//Leerzeichen in term l√∂schen
    if(term!=""){
        if(validChars(term)==false){//√úberpr√ºfung, ob term ung√ºltige Zeichen enth√§lt
            errorWindow("Nonvalid character!");
            return Intervall(NAN);
        }else if(brackets(term)==false){//√úberpr√ºfung, ob die Anzahl von "(" mit ")" in term √ºbereinstimmt
            errorWindow("Can't match delimiters!");
            return Intervall(NAN);
        }else if(intervalBrackets(term)==false){//√úberpr√ºfung, ob die Anzahl von "[" mit "]" in term √ºbereinstimmt
            errorWindow("Can't match interval delimiters!");
            return Intervall(NAN);
        }else {
            result=parseTermOfIntervals(term);//term parsen -> result
        }
    }
    return result;

}
