#ifndef SYMANTEC_H
#define SYMANTEC_H

#include <string>
#include <vector>

class Symantec
{
    std::vector<std::string> names;
    std::vector<std::string> OSnames;
    std::vector<std::string> dates;

public:
    void addNames(std::string filename);
    void listNames();
    std::vector<std::string> getNames();
    std::vector<std::string> getOSNames();
    std::vector<std::string> getDates();
};

#endif