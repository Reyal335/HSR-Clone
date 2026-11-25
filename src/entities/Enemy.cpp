#include "Enemy.hpp"
#include <string>
#include <iostream>
#include <algorithm>

void Enemy::takeDamage(int damage) {
    health = std::clamp(health - damage, 0, maxHealth);
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

void Enemy::heal(int heal) {
    health = std::clamp(health + heal, 0, maxHealth);
    std::cout << "Enemy healed " << heal << " hp";
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
