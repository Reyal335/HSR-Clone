#pragma once

#include <string>

class Passive{
private:
    std::string name;
    std::string element;
    
    int skillPoints;

public:
    virtual ~Passive() = default;
    virtual void activatePassive() = 0;
};
