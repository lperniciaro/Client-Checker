#ifndef FINALDATA_H
#define FINALDATA_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "computer.h"


class Finaldata{

    std::vector<Computer> Computers;

    public:

    //default constructor
    Finaldata();

    //default destructor
    ~Finaldata();

    //reset list
    void reset();

    //add an atera computer
    void addAtera(string name, string OSname, string OSversion, string dateSeen);


    //add an antivirus computer
    void addAntiVirus(string name, string OSname, string OSversion, string dateSeen);


    //add a screenconnect computer
    void addConnectWise(string name, string OSname, string OSversion, string dateSeen);

    //processor files, opens the CSV
    void processAtera(string filename);
    //process atera

    //process AV
    void processSentinelOne(string filename);

    //process SC
    void processConnectWise(string filename);
    
    //sorts everything
    void alphabeticallySort();

    //outputs final file
    void outputFile(string filename);


    //function to find if name already exists, if it exists return the index, else -1
    int findName(string name);
    
};

#endif