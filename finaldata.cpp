#include "finaldata.h"


Finaldata::Finaldata(){
    //do nothing lol
}

int Finaldata::findName(string name){
    int len = Computers.size();
    for(int i = 0 ; i < len ; i++){
        if(Computers[i].getName().compare(name) == 0)
            return i;
    }
    return -1;
}

void Finaldata::addAtera(string name, string OSname, string OSversion, string dateSeen){
    //first check if the PC is already there
    int index = findName(name);
    if(index != -1){ //it exists
        Computers[index].setAtera(true);
        //check if relavent info exists, if it doesn't add it
        if(Computers[index].getOSName().compare("-") == 0){
            Computers[index].setOSName(OSname);
        }
        if(Computers[index].getOSVersion().compare("-") == 0){
            Computers[index].setOSVersion(OSversion);
        }
        if(Computers[index].getDate().compare("-") == 0){
            Computers[index].setDate(dateSeen);
        }
    }else{

        //Create new computer object as it does not exist
        Computer comp;
        comp.setMachine(name, OSname, OSversion, dateSeen);
        comp.setAtera(true);
        //add to vector
        Computers.push_back(comp);
    }
}

void Finaldata::addAntiVirus(string name, string OSname, string OSversion, string dateSeen){
    //first check if the PC is already there
    int index = findName(name);
    if(index != -1){ //it exists
        Computers[index].setAntiVirus(true);
        //check if relavent info exists, if it doesn't add it
        if(Computers[index].getOSName().compare("-") == 0){
            Computers[index].setOSName(OSname);
        }
        if(Computers[index].getOSVersion().compare("-") == 0){
            Computers[index].setOSVersion(OSversion);
        }
        if(Computers[index].getDate().compare("-") == 0){
            Computers[index].setDate(dateSeen);
        }
    }else{

        //Create new computer object as it does not exist
        Computer comp;
        comp.setMachine(name, OSname, OSversion, dateSeen);
        comp.setAntiVirus(true);
        //add to vector
        Computers.push_back(comp);
    }
}

//takes CSV data and compiles into Computer objects, adds those objects to final data Computers vector
void Finaldata::processAtera(string filename){
    std::ifstream fin(filename);
    if(!fin.is_open()){
        cout << "Unable to open file: " << filename << endl;
        return;
    }

    string line;
    getline(fin, line); //get rid of junk line

    while(!fin.eof()){
        //initialize temp variables
        string line;
        string name;
        string date;
        string osname;
        string osversion;
        string osversiontemp;

        //get data from file
        getline(fin, line);
        istringstream ss(line); //string stream to extract data
        //get name
        getline(ss, name, ',');
        
        //get date
        getline(ss, date, ','); //skips past machine name, domain workgroup data
        getline(ss, date, ',');
        getline(ss, date, '"'); //gets date in the quotation marks
        getline(ss, date, '"');

        //get osname
        getline(ss, osname, ','); //go to login date
        if(ss.peek() == 34){          //last login date found, remove annoying commas in a CSV
            getline(ss, osname, '"');
            getline(ss, osname, '"');
            getline(ss, osname, ','); //clear last login date
        }

        getline(ss, osname, '"'); //clear last reboot time
        getline(ss, osname, '"');
        getline(ss, osname, ',');
        getline(ss, osname, ',');
        getline(ss, osname, ',');
        getline(ss, osname, ','); //get rid of junk
        getline(ss, osname, ','); //get osname
        
        //get osversion
        getline(ss, osversiontemp, ','); //get first part of OS
        osversion = osversiontemp + "(";
        getline(ss, osversiontemp, ',');
        osversion += osversiontemp + ")";

        //format data
        transform(name.begin(), name.end(), name.begin(), ::toupper); //capatalize names always

        for (char c: ","){ //remove the comma from the date
            date.erase(remove(date.begin(), date.end(), c), date.end());
        }

        if(!ss.fail()){
            //all data gathered successfully, create and add computer object
            addAtera(name, osname, osversion, date);
        }
    }
}


void Finaldata::processSentinelOne(string filename){
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
        string name;
        string osname;
        string osversion;
        string date;

        getline(ifs, line);
        istringstream ss(line);
        getline(ss, name, ',');
        for (int i = 0; i < 7; i++) //read past stuff I dont need
            getline(ss, date, ',');
        getline(ss, date, ','); //get date
        for (int i = 0; i < 4; i++) //read past stuff I dont need
            getline(ss, osname, ',');
        getline(ss, osname, ','); //get OS name
        getline(ss, osversion, ','); //get OS version number

        //formatting
        transform(name.begin(), name.end(), name.begin(), ::toupper); //name in uppercase
        osname.erase(0, 1); //get rid of dumb quotation mark that breaks things

        if (!ss.fail())
        {
            addAntiVirus(name, osname, osversion, date);
        }
    }
}

bool comparitor(Computer a, Computer b){
    //comparison function used for sorting
    return a.getName() < b.getName();
}

void Finaldata::alphabeticallySort(){
    int n = Computers.size();
    sort(Computers.begin(), Computers.end(), comparitor);
}

void Finaldata::outputFile(string filename){
    
    alphabeticallySort();
    //FOR BUG TESTING PURPOSES
    for(int i = 0 ; i < Computers.size() ; i++){
        cout << Computers.at(i).getName() << " " << Computers.at(i).getAntiVirus() << " " << Computers.at(i).getAtera() << " " << Computers.at(i).getSC() << endl;
    }

    ofstream outf;
    outf.open(filename);
    outf << "Computer Name, AntiVirus Y/N, Notes, Atera Y/N, Notes, ConnectWise Y/N, OS, OS Version, Last Seen, General Notes" << endl; //print header

    for(int i = 0 ; i < Computers.size() ; i++){
        outf << Computers.at(i).getName() << "," << Computers.at(i).getAntiVirus() << ",," << Computers.at(i).getAtera() << ",," << Computers.at(i).getSC() << ","
        << Computers.at(i).getOSName() << "," << Computers.at(i).getOSVersion() << "," << Computers.at(i).getDate() << "," << endl;
    }

    outf.close();
}