#include "Character.hpp"
#include <string>

void Character::takeDamage(int damage) {
    if (health - damage < 0) {
        health = 0;
    } else {
        health -= damage;        
    }
}

int Character::getHealth() const {
    return health;
}

std::string Character::getName() const {
    return name;
}

void Character::resetGameStats() {
    maxHealth = baseHealth;
    health = baseHealth;
    atk = baseAtk;
    def = baseDef;
    crit = baseCrit;
}