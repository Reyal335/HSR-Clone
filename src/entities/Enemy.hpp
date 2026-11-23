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

class Enemy{
protected:
    std::string name;
    Element element;

    // UI display stats
    int baseHealth, baseAtk, baseDef, baseSpd, baseCrit, baseUltCharge;

    // Game time stats
    int maxHealth, health, atk, def, spd, crit, shield, ultCharge;
    
    // Enemy Abilities
    std::unique_ptr<Basic> basic;
    std::unique_ptr<Passive> passive;
    std::unique_ptr<Skill> skill;
    std::unique_ptr<Ult> ult;   

    // Enemy Buffs/Debuffs
    std::vector<std::unique_ptr<StatusEffect>> status_effects;

public:
    Enemy(std::string name_, Element element_,
        int baseHealth_, int baseAtk_, int baseDef_, int baseSpd_, int baseCrit_, int baseUltCharge_) 
        : name(std::move(name_)), element(std::move(element_)),
            baseHealth(std::move(baseHealth_)), baseAtk(std::move(baseAtk_)), baseDef(std::move(baseDef_)),
            baseSpd(std::move(baseSpd_)), baseCrit(std::move(baseCrit_)), baseUltCharge(std::move(baseUltCharge_)) {}

    
    void getHealth() const;


    std::string getName() const;

    void setGameStats();

    // Outgoing actions
    void performBasic(Enemy& enemy) {
        if (basic) {
            basic->useBasic(atk, enemy);
        }
    }


    // Incoming actions
   void takeDamage(int damage);

};