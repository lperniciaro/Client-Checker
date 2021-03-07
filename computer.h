#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include <vector>
using namespace std;

class Computer{
    string name;
    string OSname;
    string OSversion;
    string dateSeen;
    bool antiVirus;
    bool atera;
    bool sc;

public:
    Computer();
    void setMachine(string name, string OSname, string OSversion, string dateSeen);
    void setName(string names);
    void setOSName(string name);
    void setOSVersion(string name);
    void setDate(string dateSeen);
    void setAntiVirus(bool yesno);
    void setAtera(bool yesno);
    void setSC(bool yesno);
    string getName();
    string getOSName();
    string getOSVersion();
    string getDate();
    string getAntiVirus();
    string getAtera();
    string getSC();
};

#endif