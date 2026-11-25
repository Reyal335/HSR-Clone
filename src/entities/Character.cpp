#include "Character.hpp"
#include <string>
#include <iostream>
#include "CharacterEnums.hpp"

enum class Element;

void Character::takeDamage(int damage) {
    if (health < damage) {
        health = 0;
    } else {
        health -= damage;        
    }
}

int Character::getHealth() const {
    // Health: ████████████████████ 163 hp
    std::cout << "Health: ";

    for (int i = 0; i < 20; i++) {
        std::cout << "█";
    }

    std::cout << " " << health;
    return health;
}

int Character::getAtk() const {
    return atk;
}

Element Character::getElement() const {
    return element;
}

std::string Character::getName() const {
    return name;
}

void Character::setGameStats() {
    maxHealth = baseHealth;
    health = baseHealth;
    atk = baseAtk;
    def = baseDef;
    spd = baseSpd;
    crit = baseCrit;
    ultCharge = baseUltCharge;
    shield = 0;
}
