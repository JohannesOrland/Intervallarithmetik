#include "gui.h"

gui::gui(QMainWindow *parent): QMainWindow(parent){
  //UI initialisieren
    setupUi(this);
    tabs->setCurrentIndex(0);//Tabindex auf ersten Tab setzen
    checkBox31->setChecked(true);//Checkbox31 im Tab "Gleichungssystem" auf checked setzen
    output->setReadOnly(true);//Output auf "readonly" setzen
    inputStart->setText("[1,2]");//Text von InputX auf 1 setzen
  //Icon setzen
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/ressources/int.png"), QSize(), QIcon::Normal, QIcon::Off);
    QApplication::setWindowIcon(icon);
    QWidget::setWindowIcon(QIcon::QIcon());
  //Schriftart
    QFontDatabase::addApplicationFont (":/ressources/monaco.ttc");
    QFont monaco("Monaco", 12, QFont::Normal, false);
    inputIntervall->setFont(monaco);
    inputFunction->setFont(monaco);
    inputDerivate->setFont(monaco);
    inputStart->setFont(monaco);
    inputA->setFont(monaco);
    inputB->setFont(monaco);
    inputC->setFont(monaco);
    inputD->setFont(monaco);
    inputE->setFont(monaco);
    inputF->setFont(monaco);
    output->setFont(monaco);
  //Shortcuts
    clearInputSc = new QShortcut(QKeySequence("Shift+Alt+C"), this); //Shortcut für clearInput()
    connect(clearInputSc, SIGNAL(activated()), this, SLOT(clearInput()));//Shortcut mit clearInput() verbinden
    clearOutputSc = new QShortcut(QKeySequence("Alt+C"), this); //Shortcut für clearOutput()
    connect(clearOutputSc, SIGNAL(activated()), this, SLOT(clearOutput()));//Shortcut mit clearOutput() verbinden
    calcSc = new QShortcut(QKeySequence("Ctrl+R"), this);//Shortcut für calculateIntervall()
    connect(calcSc, SIGNAL(activated()), this, SLOT(calcShortcut()));//Shortcut mit calculateIntervall() verbinden
  //Output initialisieren
    output->setText("Output:");
    output->append("-------");
  //Buttons mit Methoden verbinden
    connect(inputIntervall, SIGNAL(returnPressed()), this, SLOT(calculateIntervall()));
    connect(calcButton1, SIGNAL(clicked()), this, SLOT(calculateIntervall()));
    connect(inputFunction, SIGNAL(returnPressed()), this, SLOT(calculateFunction()));
    connect(inputStart, SIGNAL(returnPressed()), this, SLOT(calculateFunction()));
    connect(inputDerivate, SIGNAL(returnPressed()), this, SLOT(calculateFunction()));
    connect(calcButton2, SIGNAL(clicked()), this, SLOT(calculateFunction()));
    connect(inputA, SIGNAL(returnPressed()), this, SLOT(calculateLgs()));
    connect(inputB, SIGNAL(returnPressed()), this, SLOT(calculateLgs()));
    connect(inputC, SIGNAL(returnPressed()), this, SLOT(calculateLgs()));
    connect(inputD, SIGNAL(returnPressed()), this, SLOT(calculateLgs()));
    connect(inputE, SIGNAL(returnPressed()), this, SLOT(calculateLgs()));
    connect(inputF, SIGNAL(returnPressed()), this, SLOT(calculateLgs()));
    connect(calcButton3, SIGNAL(clicked()), this, SLOT(calculateLgs()));
    connect(clearButton1, SIGNAL(clicked()), this, SLOT(clearOutput()));
    connect(clearButton2, SIGNAL(clicked()), this, SLOT(clearOutput()));
    connect(clearButton3, SIGNAL(clicked()), this, SLOT(clearOutput()));
}

gui::~gui(){
    delete clearInputSc;
    delete clearOutputSc;
    delete calcSc;
}

void gui::calculateIntervall(){
    string term=((inputIntervall->text()).toLower()).toStdString();
    if(term=="info" || term=="hilfe" || term=="about" || term=="help"){
        inputIntervall->clear();
        infoWindow();
    } else{
        Intervall result=parse(term);
        if(result.getInf()==result.getInf()){
            QString tmp="";
            if(term.find_first_of("+-*/&|")!=string::npos){
                tmp=QString::fromStdString(term) +"=";
            }
            output->append(tmp+QString::fromStdString(result.printToString()));//Ausgabe von result
        }
    }
}

void gui::calculateLgs(){
  //Gleichungssystem von Zahleingaben berechnen
    Intervall a=parse((inputA->text()).toStdString()),
              b=parse((inputB->text()).toStdString()),
              c=parse((inputC->text()).toStdString()),
              d=parse((inputD->text()).toStdString()),
              e=parse((inputE->text()).toStdString()),
              f=parse((inputF->text()).toStdString());
    if((a*e-b*d).getInf()<=0 && (a*e-b*d).getSup()>=0){
        output->append("x=nan");
        output->append("y=nan");
        errorWindow("Can't solve system!\nCause:(a*e-b*d)="+(a*e-b*d).printToString());
    } else{
        if(checkBox31->isChecked()==true){
            output->append("");
            output->append("==========");
            output->append(QString::fromStdString(a.printToString())+
                           "*x+"+QString::fromStdString(b.printToString())+
                           "*y="+QString::fromStdString(c.printToString()));
            output->append(QString::fromStdString(d.printToString())+
                           "*x+"+QString::fromStdString(e.printToString())+
                           "*y="+QString::fromStdString(f.printToString()));
            output->append("");
        }
        output->append("x="+QString::fromStdString(((c*e-b*f)/(a*e-b*d)).printToString()));
        output->append("y="+QString::fromStdString(((a*f-c*d)/(a*e-b*d)).printToString()));
        output->append("");
    }
}

void gui::calculateFunction(){
    string term=((inputFunction->text()).toLower()).toStdString();
    string term2=((inputDerivate->text()).toLower()).toStdString();
    if(term=="info" || term=="hilfe" || term=="about" || term=="help"){
        inputFunction->clear();
        infoWindow();
    } else if(term2=="info" || term2=="hilfe" || term2=="about" || term2=="help"){
        inputDerivate->clear();
        infoWindow();
    } else{
        Intervall start=parseTermOfIntervals((inputStart->text()).toStdString());
        Funktion func;
        Funktion derive;
        int retVal = func.parseFunction(term);
        int retval2 = derive.parseFunction(term2);
        double result = func.newtonIntervall(start,derive);
        stringstream number;
        if(retVal==0 && retval2==0){
            number << result;
        }
        QString input = input.fromStdString(number.str());
        if(input.toDouble()==input.toDouble()){
            output->append("");
            output->append("f(x)="+QString::fromStdString(term));
            output->append("f'(x)="+QString::fromStdString(term2));
            output->append("f("+input+")=0");
            inputIntervall->clear();
        } else {
            errorWindow("Can't evaluate!");
        }
    }
}

void gui::clearOutput(){
  //Output reinitialisieren
    output->clear();
    output->setText("Output:");
    output->append("-------");
}

void gui::clearInput(){
    switch(tabs->currentIndex()){
        case 0: inputIntervall->clear();
                break;
        case 1: inputFunction->clear();
                break;
        case 2: inputA->clear();
                inputB->clear();
                inputC->clear();
                inputD->clear();
                inputE->clear();
                inputF->clear();
                break;
        default: break;
    }
}

void gui::calcShortcut(){
    switch(tabs->currentIndex()){
        case 0: calculateIntervall();
                break;
        case 1: calculateFunction();
                break;
        case 2: calculateLgs();
                break;
        default: break;
    }
}

void errorWindow(string str){
  //Fehlermeldung initialisieren
    QMessageBox msgBox;
    msgBox.setWindowTitle("An error occured.");
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setText("An error occured.");
    msgBox.setInformativeText(QString::fromStdString(str));
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}

void infoWindow(){
    QMessageBox msgBox;
    msgBox.setWindowTitle("About");
    QPixmap icon;
    QImage image=QImage(":/ressources/int.png");
    image=image.scaled(128,128,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    icon.convertFromImage(image);
    msgBox.setIconPixmap(icon);
    msgBox.setText("About: Intervallarithmetik");
    msgBox.setInformativeText("Version 1.0\n14.7.2011\nVon Johannes Orland und Lukas Wandelt");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
}
