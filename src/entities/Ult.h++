#pragma once

#include <string>
#include "Enums.hpp"

class Ult{
private:
    std::string name;
    Element element;
    
    int charge;

public:
    Ult(std::string Name_, Element Element_, int charge_)
        : name(std::move(Name_)), element(std::move(Element_)), charge(std::move(charge_)) {}

    virtual ~Ult() = default;
    virtual void useUlt() = 0;
};
