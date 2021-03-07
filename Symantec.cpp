#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Symantec.h"
#include <algorithm>

using namespace std;

void Symantec::addNames(string filename)
{
    ifstream ifs(filename);
    if (!ifs.is_open())
    { //if the file cannot open give error message
        cout << "Unable to open file: " << filename << endl;
        return;
    }

    string line;
    getline(ifs, line); //get rid of junk line

    while (!ifs.eof())
    {
        //collect data from file
        string line;
        getline(ifs, line);
        istringstream ss(line);
        string name1;
        getline(ss, name1, ','); //scan until , is found
        istringstream ss2(name1);
        string name;
        getline(ss2, name, '.'); //check if a . is found and kill after that
        transform(name.begin(), name.end(), name.begin(), ::toupper);

        getline(ss, name1, ',');
        getline(ss, name1, ','); //find OS version

        string date;
        getline(ss, date, ','); //find date
        
        if (!ss.fail())
        {
            names.push_back(name);
            OSnames.push_back(name1);
            dates.push_back(date);
        }
    }
}

void Symantec::listNames()
{
    for (int i = 0; i < names.size(); i++)
    {
        cout << OSnames.at(i) << " " << dates.at(i) << " " << names.at(i) << endl;
    }
}

vector<string> Symantec::getNames(){
    return names;
}

vector<string> Symantec::getDates(){
    return dates;
}

vector<string> Symantec::getOSNames(){
    return OSnames;
}