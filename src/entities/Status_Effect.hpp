#pragma once
#include <string>
#include "Enums.hpp"
#include <memory>

class StatusEffect {
private:
    std::string name;
    Element element;

public:
    StatusEffect(std::string _name, Element _element) : name(std::move(_name)), element(std::move(_element)) {}
    virtual ~StatusEffect() = default;
    void invokeEffect();
};