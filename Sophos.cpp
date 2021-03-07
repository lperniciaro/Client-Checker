#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Sophos.h"
#include <algorithm>

using namespace std;

void Sophos::addNames(string filename)
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
        string osname;
        getline(ss, name, ',');
        getline(ss, name, ',');
        getline(ss, osname, ',');
        transform(name.begin(), name.end(), name.begin(), ::toupper);

        if (!ss.fail())
        {
            names.push_back(name);
            OSnames.push_back(osname);
        }
    }
}

void Sophos::addNamesSentinel(string filename)
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
        //collect data
        string line;
        getline(ifs, line);
        istringstream ss(line);
        string name;
        string osname;
        getline(ss, name, ',');
        for (int i = 0; i < 12; i++) //read past stuff I dont need
            getline(ss, osname, ',');
        getline(ss, osname, ','); //get OS Version and name
        transform(name.begin(), name.end(), name.begin(), ::toupper);

        osname.erase(0, 1); //get rid of dumb quotation mark that breaks things

        if (!ss.fail())
        {
            names.push_back(name);
            OSnames.push_back(osname);
        }
    }
}

void Sophos::listNames()
{
    for (int i = 0; i < names.size(); i++)
    {
        cout << names.at(i) << endl;
        cout << OSnames.at(i) << endl;
    }
}

std::vector<std::string> Sophos::getNames()
{
    return names;
}

std::vector<std::string> Sophos::getOSNames()
{
    return OSnames;
}