#include "computer.h"

using namespace std;

//Default constructer, nothing
Computer::Computer(){
    name = "-";
    OSname = "-";
    OSversion = "-";
    dateSeen = "-";
    antiVirus = false;
    atera = false;
    sc = false;
}

//used to set initial data for checker
void Computer::setMachine(string name, string OSname, string OSversion, string dateSeen){
    this->name = name;
    this->OSname = OSname;
    this->OSversion = OSversion;
    this->dateSeen = dateSeen;
}

//function to set boolean values
void Computer::setAntiVirus(bool yesno){
    antiVirus = yesno;
}

void Computer::setAtera(bool yesno){
    atera = yesno;
}

void Computer::setSC(bool yesno){
    sc = yesno;
}

void Computer::setOSName(string name){
    OSname = name;
}

void Computer::setOSVersion(string name){
    OSversion = name;
}

void Computer::setDate(string name){
    dateSeen = name;
}

string Computer::getName(){
    return name;
}
string Computer::getOSName(){
    return OSname;
}
string Computer::getDate(){
    return dateSeen;
}

string Computer::getOSVersion(){
    return OSversion;
}

string Computer::getAntiVirus(){
    if(antiVirus)
        return "Y";
    return "N";
}
string Computer::getAtera(){
    if(atera)
        return "Y";
    return "N";
}
string Computer::getSC(){
    if(sc)
        return "Y";
    return "N";
}