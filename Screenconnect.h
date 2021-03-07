#ifndef SCREENCONNECT_H
#define SCREENCONNECT_H

#include <string>
#include <vector>

class Screenconnect{

    std::vector<std::string> names;
    public:
        void addNames(std::string filename);
        void listNames();
        std::vector<std::string> getNames();

};

#endif