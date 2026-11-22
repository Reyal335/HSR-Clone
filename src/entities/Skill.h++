#include <string>
#include "Enums.hpp"

class Skill{
private:
    std::string name;
    Element element;
    
    int skillPoints;

public:
    Skill(std::string Name_, Element Element_, int skillPoints_)
        : name(std::move(Name_)), element(std::move(Element_)), skillPoints(std::move(skillPoints_)) {}

    virtual ~Skill() = default;
    virtual void useSkill() = 0;
};