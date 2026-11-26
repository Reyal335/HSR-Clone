#pragma once

#include <string>
#include "CharacterEnums.hpp"

struct BattleContext;

class Skill{
private:
    std::string name;
    Element element;
    
    int skillPoints;

public:
    Skill(std::string Name_, Element Element_, int skillPoints_)
        : name(std::move(Name_)), element(std::move(Element_)), skillPoints(std::move(skillPoints_)) {}

    virtual ~Skill() = default;
    virtual void useSkill(BattleContext& context) = 0;
};
