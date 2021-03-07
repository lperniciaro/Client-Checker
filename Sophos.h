#ifndef SOPHOS_H
#define SOPHOS_H

#include <string>
#include <vector>

class Sophos{

    std::vector<std::string> names;
    std::vector<std::string> OSnames;

    public:
        void addNames(std::string filename);
        void addNamesSentinel(std::string filename);
        void listNames();
        std::vector<std::string> getNames();
        std::vector<std::string> getOSNames();
};

#endif