#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Screenconnect.h"
#include <algorithm>

using namespace std;


void Screenconnect::addNames(string filename)
{
    ifstream ifs(filename);
    if (!ifs.is_open())
    {
        cout << "Unable to open file: " << filename << endl;
        return;
    }

    string name;
    getline(ifs, name, ',');
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    names.push_back(name);

    while (!ifs.eof())
    {
        string name;
        getline(ifs, name, ',');
        name.erase(0,1); //erase the annoying space
        if(!ifs.fail()){
            transform(name.begin(), name.end(), name.begin(), ::toupper);
            names.push_back(name);
        }
    }
}

void Screenconnect::listNames()
{
    for (int i = 0; i < names.size(); i++)
    {
        cout << names.at(i) << endl;
    }
}

std::vector<std::string> Screenconnect::getNames(){
    return names;
}