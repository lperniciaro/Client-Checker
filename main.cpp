#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <vector>
#include "Atera.h"
#include "Screenconnect.h"
#include "Sophos.h"
#include "Finaldata.h"
#include "Symantec.h"
#include <algorithm>

using namespace std;

void printMenu()
{
    cout << "--------------------------------------------------" << endl;
    cout << " '1': Load ScreenConnect File" << endl;
    cout << " '2': Load Atera File" << endl;
    cout << " '3': Load Symantec File" << endl;
    cout << " '4': Load Sophos File" << endl;
    cout << " '5': Output Client System Check" << endl;
    cout << " '6': Load SentinelOne File" << endl;
    cout << " '7': List Atera Computers" << endl;
    cout << " '8': List Symantec/Sophos Computers" << endl;
    cout << " 'Q': Quit" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl
         << "Please enter your choice: ";
}

void processLoadSC(Screenconnect &screenconnect)
{
    string filename;
    cout << "Please enter filename: ";
    cin >> filename;
    screenconnect.addNames(filename);
}

void processLoadAtera(Atera &atera)
{
    string filename;
    cout << "Please enter filename: ";
    cin >> filename;
    atera.addNames(filename);
}

void processLoadSymantec(Symantec &symantec)
{
    string filename;
    cout << "Please enter filename: ";
    cin >> filename;
    symantec.addNames(filename);
}

void processLoadSophos(Sophos &sophos)
{
    string filename;
    cout << "Please enter filename: ";
    cin >> filename;
    sophos.addNames(filename);
}

bool sentUsed = false;

void processLoadSentinelOne(Sophos &sophos)
{
    string filename;
    cout << "Please enter filename: ";
    cin >> filename;
    sophos.addNamesSentinel(filename);
    sentUsed = true;
}

bool mycomp(Finaldata a, Finaldata b)
{
    //returns 1 if string a is alphabetically
    //less than string b
    //quite similar to strcmp operation
    return a.getName() < b.getName();
}

vector<Finaldata> alphabaticallySort(vector<Finaldata> a)
{
    int n = a.size();
    //mycomp function is the defined function which
    //sorts the strings in alphabatical order
    sort(a.begin(), a.end(), mycomp);
    return a;
}

void processOutputSystemCheck(Atera &atera, Screenconnect &screenconnect, Sophos &sophos, Symantec &symantec) //this one is for sophos
{
    vector<Finaldata> finaldata; //initialize finaldata vector
    bool sophUsed = false;

    for (int i = 0; i < sophos.getNames().size(); i++)
    {                                                                                                       //add sophos names
        Finaldata data = Finaldata(sophos.getNames().at(i), sophos.getOSNames().at(i), true, false, false); //set sophos to true
        finaldata.push_back(data);
        sophUsed = true;
    }

    for (int i = 0; i < symantec.getNames().size(); i++)
    {                                                                                                                                      //add symantec names
        Finaldata data = Finaldata(symantec.getNames().at(i), symantec.getOSNames().at(i), true, false, false, symantec.getDates().at(i)); //set symantec to true
        finaldata.push_back(data);
    }

    bool foundmatch = false;
    for (int i = 0; i < screenconnect.getNames().size(); i++)
    { //go through screenconnect list
        for (int k = 0; k < finaldata.size(); k++)
        { //search main list
            if (finaldata.at(k).getName().compare(screenconnect.getNames().at(i)) == 0)
            { //if final data name = screenconnect name
                foundmatch = true;
                finaldata.at(k).setSC(true); //set screenconnect boolean to true
                break;
            }
        }
        if (!foundmatch)
        {                                                                                      //no match found at the end
            Finaldata thedata = Finaldata(screenconnect.getNames().at(i), false, false, true); //append non matching sophos name to end of list
            finaldata.push_back(thedata);
        }
        else
        {
            foundmatch = false;
        }
    }

    for (int i = 0; i < atera.getNames().size(); i++)
    { //same thing as before, but with atera
        for (int k = 0; k < finaldata.size(); k++)
        {
            if (finaldata.at(k).getName().compare(atera.getNames().at(i)) == 0)
            {
                foundmatch = true;
                finaldata.at(k).setAtera(true);
                finaldata.at(k).setOSName(atera.getOSNames().at(i)); //if they match, add the atera OS name
                if (finaldata.at(k).getDate().compare("Online") != 0)
                { //if it's online dont bother printing the date
                    finaldata.at(k).setDate(atera.getDates().at(i));
                }
                break;
            }
        }
        if (!foundmatch)
        {
            Finaldata thedata = Finaldata(atera.getNames().at(i), atera.getOSNames().at(i), false, true, false, atera.getDates().at(i));
            finaldata.push_back(thedata);
        }
        else
        {
            foundmatch = false;
        }
    }

    finaldata = alphabaticallySort(finaldata);
    //ALL DATA CRUNCHING COMPLETE, NOW PRINT IT RIGHT
    for (int i = 0; i < finaldata.size(); i++)
    {
        cout << finaldata.at(i).getName() << " " << finaldata.at(i).getSophos() << " " << finaldata.at(i).getAtera() << " " << finaldata.at(i).getSC() << endl;
    }
    ofstream output;
    output.open("final.csv");
    if (sophUsed)
    { //check whether to use sophos or symantec
        if (sentUsed)
        {
            output << "Computer Name,SentinelOne Y/N,SO Notes,Atera Y/N,Atera Notes,Screenconnect Y/N,OS Version,General Notes" << endl;
        }
        else
        {
            output << "Computer Name,Sophos Y/N,Sophos Notes,Atera Y/N,Atera Notes,Screenconnect Y/N,OS Version,General Notes" << endl;
        }
    }
    else
    {
        output << "Computer Name,Symantec Y/N,Symantec Notes,Atera Y/N,Atera Notes,Screenconnect Y/N,OS Version,General Notes" << endl;
    }

    for (int i = 0; i < finaldata.size(); i++)
    {
        if (finaldata.at(i).getDate().compare("Online") == 0 || finaldata.at(i).getDate().compare("") == 0)
        { //If a computer is online, dont print it in notes to eliminate clutter
            output << finaldata.at(i).getName() << "," << finaldata.at(i).getSophos() << ",," << finaldata.at(i).getAtera() << ",," << finaldata.at(i).getSC() << "," << finaldata.at(i).getOSName() << "," << endl;
        }
        else
        {
            output << finaldata.at(i).getName() << "," << finaldata.at(i).getSophos() << ",," << finaldata.at(i).getAtera() << ",," << finaldata.at(i).getSC() << "," << finaldata.at(i).getOSName() << ",Last online " << finaldata.at(i).getDate() << endl;
        }
    }

    output.close();
}

int main()
{

    Atera atera;
    Screenconnect screenconnect;
    Sophos sophos;
    Symantec symantec;
    char choice = 'a';

    do
    {
        printMenu();
        cin >> choice;
        switch (tolower(choice))
        {
        case '1':
            processLoadSC(screenconnect);
            break;
        case '2':
            processLoadAtera(atera);
            break;
        case '3':
            processLoadSymantec(symantec);
            break;
        case '4':
            processLoadSophos(sophos);
            break;
        case '5':
            processOutputSystemCheck(atera, screenconnect, sophos, symantec);
            break;
        case '6':
            processLoadSentinelOne(sophos);
            break;
        case '7':
            atera.listNames();
            break;
        case '8':
            sophos.listNames();
            break; //do something Sophos or Symantec
        case 'q':
            break; // do nothing
        default:
            cout << choice << " is an invalid option. Please try again." << endl;
        }
    } while (tolower(choice) != 'q');
}