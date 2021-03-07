#ifndef FINALDATA_H
#define FINALDATA_H

#include <string>
#include <vector>
using namespace std;

class Finaldata{
    string name;
    string OSname;
    string date;
    bool sophos;
    bool atera;
    bool sc;

public:
    Finaldata(string name, bool sophos, bool atera, bool sc);
    Finaldata(string name, string OSname, bool sophos, bool atera, bool sc);
    Finaldata(string name, string OSname, bool sophos, bool atera, bool sc, string date);
    void setName(string names);
    void setOSName(string name);
    void setDate(string date);
    void setSophos(bool yesno);
    void setAtera(bool yesno);
    void setSC(bool yesno);
    string getName();
    string getOSName();
    string getDate();
    string getSophos();
    string getAtera();
    string getSC();
};

#endif