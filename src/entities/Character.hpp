#pragma once
#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include "Skill.hpp"
#include "Basic.hpp"
#include "Passive.hpp"
#include "Ult.hpp"
#include "CharacterEnums.hpp"
#include "Status_Effect.hpp"
#include "../gameplay/BattleContext.hpp"
#include "Entity.hpp"

class BattleContext;
class Enemy;
class Entity;

class Character : public Entity {
protected:
    std::string name;
    Path path;
    Element element;

    // UI display stats
    int baseHealth, baseAtk, baseDef, baseSpd, baseCrit, baseUltCharge;

    // Game time stats
    int maxHealth, health, atk, def, spd, crit, shield, ultCharge;

    bool isAlive;
    
    // Character Abilities
    std::unique_ptr<Basic> basic;
    std::unique_ptr<Passive> passive;
    std::unique_ptr<Skill> skill;
    std::unique_ptr<Ult> ult;   

    // Character Buffs/Debuffs
    std::vector<std::unique_ptr<StatusEffect>> status_effects;

public:
    Character(int id, std::string name_, Path path_, Element element_,
        int baseHealth_, int baseAtk_, int baseDef_, int baseSpd_, int baseCrit_, int baseUltCharge_) 
        : name(std::move(name_)), path(std::move(path_)), element(std::move(element_)),
            baseHealth(baseHealth_), baseAtk(baseAtk_), baseDef(baseDef_),
            baseSpd(baseSpd_), baseCrit(baseCrit_), baseUltCharge(baseUltCharge_), Entity(id) {}

    void takeDamage(int damage);

    // Getters for in game stats
    int getHealth() const;
    int getAtk() const;
    Element getElement() const;

    std::string getName() const;

    void setGameStats();

    void performBasic(BattleContext& battleContext) {
        if (basic) {
            basic->useBasic(battleContext);
        }
    }

    void takeTurn() override;

    // Passives activators for listeners

};
