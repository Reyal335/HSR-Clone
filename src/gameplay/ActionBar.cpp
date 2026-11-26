#include "ActionBar.hpp"
#include "../entities/Character.hpp"
#include "../entities/Enemy.hpp"
#include "../entities/Entity.hpp"
#include <deque>
#include <memory>
#include <iostream>

const std::deque<Entity*>& ActionBar::getQueue() {
    return queue;
}

void ActionBar::loadQueue(std::vector<std::unique_ptr<Character>>& characters, 
    std::array<std::unique_ptr<Enemy>, 5>& enemies) {
    // Load Characters
    for (const auto& character: characters) {
        if (character) {
            queue.push_back(character.get());
        }
    }

    // Load Enemies
    for (const auto& enemy : enemies) {
        if (enemy) {
            queue.push_back(enemy.get());
        }
       
    }
    // To be implemented, sort by spd, or in the future by game rules
}

void ActionBar::printQueue() {
    for (const auto& entity:queue) {
        std::cout << "[  ";
        std::cout << entity->getId();
        if (auto* character = dynamic_cast<Character*>(entity)) {
            std::cout << character->getName() << " ";
        } else if (auto* enemy = dynamic_cast<Enemy*>(entity)) {
            std::cout << enemy->getName() << " ";
        }
        std::cout << "  ]";
    }
}
