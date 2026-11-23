#include "Enemy.hpp"
#include <string>
#include <iostream>

void Enemy::takeDamage(int damage) {
    if (damage > health) {
        health = 0;
    } else {
        health -= damage;
    }
    std::cout << "Enemy took damage!" << health;
}

void Enemy::getHealth() const {
    // Health: ████████████████████ 163 hp
    std::cout << "Health: ";

    for (int i = 0; i < 20; i++) {
        std::cout << "█";
    }

    std::cout << " " << health;

}

std::string Enemy::getName() const {
    return name;
}

void Enemy::setGameStats() {
    maxHealth = baseHealth;
    health = baseHealth;
    atk = baseAtk;
    def = baseDef;
    spd = baseSpd;
    crit = baseCrit;
    ultCharge = baseUltCharge;
    shield = 0;
}
