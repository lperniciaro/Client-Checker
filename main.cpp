#include "finaldata.h"

void printMenu(){
    cout << "--------------------------------------------------" << endl;
    cout << " '1': Load ConnectWise File" << endl;
    cout << " '2': Load Atera File" << endl;
    cout << " '3': Load SentinelOne File" << endl;
    cout << " '4': Load Sophos File" << endl;
    cout << " '5': OUTPUT SYSTEM CHECK" << endl;
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
        cout << "Current version: 1.02" << endl;
        printMenu();
        cin >> choice;
        switch (tolower(choice))
        {
        case '1':
            filename = filePrompt();
            computers.processConnectWise(filename);
            break;
        case '2': //load atera
            filename = filePrompt();
            computers.processAtera(filename);
            break;
        case '3':
            //process sentinelone CSV
            filename = filePrompt();
            computers.processSentinelOne(filename);
            break;
        case '4':
            filename = filePrompt();
            computers.processSophos(filename);
            break;
        case '5':
            //output check
            filename = filePrompt();
            computers.outputFile(filename);
            //cleanup
            computers.reset();
            break;
        case 'q':
            break; // do nothing
        default:
            cout << choice << " is an invalid option. Please try again." << endl;
        }
    } while (tolower(choice) != 'q');
}