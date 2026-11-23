#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Skill.h++"
#include "Basic.h++"
#include "Passive.h++"
#include "Ult.h++"
#include "Enums.hpp"
#include "Status_Effect.hpp"

class Enemy;

class Character{
protected:
    std::string name;
    Path path;
    Element element;

    // UI display stats
    int baseHealth, baseAtk, baseDef, baseSpd, baseCrit, baseUltCharge;

    // Game time stats
    int maxHealth, health, atk, def, spd, crit, shield, ultCharge;
    
    // Character Abilities
    std::unique_ptr<Basic> basic;
    std::unique_ptr<Passive> passive;
    std::unique_ptr<Skill> skill;
    std::unique_ptr<Ult> ult;   

    // Character Buffs/Debuffs
    std::vector<std::unique_ptr<StatusEffect>> status_effects;

public:
    Character(std::string name_, Path path_, Element element_,
        int baseHealth_, int baseAtk_, int baseDef_, int baseSpd_, int baseCrit_, int baseUltCharge_) 
        : name(std::move(name_)), path(std::move(path_)), element(std::move(element_)),
            baseHealth(baseHealth_), baseAtk(baseAtk_), baseDef(baseDef_),
            baseSpd(baseSpd_), baseCrit(baseCrit_), baseUltCharge(baseUltCharge_) {}

    void takeDamage(int damage);
    void getHealth() const;


    std::string getName() const;

    void setGameStats();

    void performBasic(Enemy& enemy) {
        if (basic) {
            basic->useBasic(atk, enemy);
        }
    }

};
