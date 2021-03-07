#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Atera.h"
#include <algorithm>

using namespace std;

void Atera::addNames(string filename)
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
        string name;
        getline(ss, name, ',');
        transform(name.begin(), name.end(), name.begin(), ::toupper); //capatalize

        string date;
        getline(ss, date, ',');
        getline(ss, date, ','); 
        getline(ss, date, '"'); //get rid of junk
        getline(ss, date, '"'); //get date

        string osname;
        getline(ss, osname, ',');
        if(ss.peek() == 34)    //if it finds a last login date
        {
            getline(ss, osname, '"');
            getline(ss, osname, '"');
            getline(ss, osname, ',');//clear last login date
        }
        
        getline(ss, osname, '"'); //clear last reboot time
        getline(ss, osname, '"');
        getline(ss, osname, ',');
        getline(ss, osname, ',');
        getline(ss, osname, ',');
        getline(ss, osname, ','); //get rid of junk
        getline(ss, osname, ','); //get osname

        string chars = ",";

        for (char c: chars){ //remove the comma from the date
            date.erase(remove(date.begin(), date.end(), c), date.end());
        }

        if (!ss.fail())
        {
            names.push_back(name);
            dates.push_back(date);
            OSnames.push_back(osname);
        }
    }
}

void Atera::listNames()
{
    for (int i = 0; i < names.size(); i++)
    {
        cout << names.at(i) << " " << dates.at(i) << " " << OSnames.at(i) << endl;
    }
}

std::vector<std::string> Atera::getNames()
{
    return names;
}

std::vector<std::string> Atera::getDates()
{
    return dates;
}

std::vector<std::string> Atera::getOSNames()
{
    return OSnames;
}