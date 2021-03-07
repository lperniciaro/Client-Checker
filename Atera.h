#ifndef ATERA_H
#define ATERA_H

#include <string>
#include <vector>

class Atera
{

    std::vector<std::string> names;
    std::vector<std::string> dates;
    std::vector<std::string> OSnames;

public:
    void addNames(std::string filename);
    void listNames();
    std::vector<std::string> getNames();
    std::vector<std::string> getDates();
    std::vector<std::string> getOSNames();
};

#endif