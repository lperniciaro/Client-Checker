#include "finaldata.h"

void printMenu(){
    cout << "--------------------------------------------------" << endl;
    cout << " '1': Load ScreenConnect File" << endl;
    cout << " '2': Load Atera File" << endl;
    cout << " '3': Load Symantec File" << endl;
    cout << " '4': Load Sophos File" << endl;
    cout << " '5': Load SentinelOne File" << endl;
    cout << " '6': OUTPUT SYSTEM CHECK" << endl;
    cout << " '7': List Atera Computers" << endl;
    cout << " '8': List Symantec/Sophos Computers" << endl;
    cout << " 'Q': Quit" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << endl
         << "Please enter your choice: ";
}

string filePrompt(){
    string filename;
    cout << "Please enter filename: ";
    cin >> filename;
    return filename;
}

int main(){
    char choice = 'a';
    string filename;
    Finaldata computers;

    do{
        printMenu();
        cin >> choice;
        switch (tolower(choice))
        {
        case '1':
            filename = filePrompt();
            //do screenconnect stuff here
            break;
        case '2': //load atera
            filename = filePrompt();
            computers.processAtera(filename);
            break;
        case '3':
            //processLoadSymantec(symantec);
            break;
        case '4':
            //processLoadSophos(sophos);
            break;
        case '5':
            //process sentinelone CSV
            filename = filePrompt();
            computers.processSentinelOne(filename);
            break;
        case '6':
        //output check
            filename = filePrompt();
            computers.outputFile(filename);
            break;
        case '7':
            //atera.listNames();
            break;
        case '8':
            //sophos.listNames();
            break; //do something Sophos or Symantec
        case 'q':
            break; // do nothing
        default:
            cout << choice << " is an invalid option. Please try again." << endl;
        }
    } while (tolower(choice) != 'q');
}