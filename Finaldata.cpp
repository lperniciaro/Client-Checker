#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Finaldata.h"
#include <algorithm>

using namespace std;

Finaldata::Finaldata(string name, bool sophos, bool atera, bool sc){
    this->name = name;
    OSname = "-";
    this->sophos = sophos;
    this->atera = atera;
    this->sc = sc;
    this->date = "";
}

Finaldata::Finaldata(string name, string OSname, bool sophos, bool atera, bool sc){
    this->name = name;
    this->OSname = OSname;
    this->sophos = sophos;
    this->atera = atera;
    this->sc = sc;
    this->date = "";
}

Finaldata::Finaldata(string name, string OSname, bool sophos, bool atera, bool sc, string date){
    this->name = name;
    this->OSname = OSname;
    this->sophos = sophos;
    this->atera = atera;
    this->sc = sc;
    this->date = date;
}

void Finaldata::setName(string names){
    name = names;
}
void Finaldata::setOSName(string name){
    OSname = name;
}
void Finaldata::setDate(string date){
    this->date = date;
}
void Finaldata::setSophos(bool yesno){
    sophos = yesno;
}
void Finaldata::setAtera(bool yesno){
    atera = yesno;
}
void Finaldata::setSC(bool yesno){
    sc = yesno;
}
string Finaldata::getName(){
    return name;
}
string Finaldata::getOSName(){
    return OSname;
}
string Finaldata::getDate(){
    return date;
}
string Finaldata::getSophos(){
    if(sophos){
        return "Y";
    }
    return "N";
}
string Finaldata::getAtera(){
    if(atera){
        return "Y";
    }
    return "N";
}
string Finaldata::getSC(){
    if(sc){
        return "Y";
    }
    return "N";
}