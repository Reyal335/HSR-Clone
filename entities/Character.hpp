#pragma once
#include <string>
#include <memory>
#include "Skill.h++"
#include "Basic.h++"
#include "Passive.h++"
#include "Ult.h++"

class Character{
protected:
    std::string name;
    std::string path;
    std::string element;

    // UI display stats
    int baseHealth, baseAtk, baseDef, baseSpd, baseCrit;

    // Game time stats
    int maxHealth, health, atk, def, spd, crit;
    
    std::unique_ptr<Basic> basic;
    std::unique_ptr<Passive> passive;
    std::unique_ptr<Skill> skill;
    std::unique_ptr<Ult> ult;

public:
    Character(std::string name_, std::string path_, std::string element_,
        int baseHealth_, int baseAtk_, int baseDef_, int baseSpd_, int baseCrit_) 
        : name(std::move(name_)), path(std::move(path_)), element(std::move(element_)),
            baseHealth(std::move(baseHealth_)), baseAtk(std::move(baseAtk_)), baseDef(std::move(baseDef_)),
            baseSpd(std::move(baseSpd_)), baseCrit(std::move(baseCrit_)) {}

    void takeDamage(int damage);
    int getHealth() const;
    std::string getName() const;
    void resetGameStats();

    void performBasic() {
        if (basic) {
            basic->useBasic();
        }
    }

};