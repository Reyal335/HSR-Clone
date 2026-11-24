#include "EnemyLineup.hpp"
#include "Enemy.hpp"
#include <iostream>
#include <memory>
#include <random>

class Enemy;

void EnemyLineup::placeEnemy(std::unique_ptr<Enemy> newEnemy) {
    if (!newEnemy) {
        std::cout << "Cannot put in anything that does not exist";
    } else if (count == 5) {
        std::cout << "Slots are full and cannot put a new enemy";
    } else {
        if (count == 0) {
            slots[defaultIndex] = std::move(newEnemy);
            count++;
        } else {
            std::string left = "Left";
            std::string right = "Right";

            std::random_device rd;
            std::mt19937 gen(rd());
            std::bernoulli_distribution coinFlip(0.5);

            /** 
             * if there is only the middle enemy, randomly decide to place it either left
             * or right, random selection only happens once
             * */ 
            if (count == 1) {
                lastSide = coinFlip(gen) ? Sides::left : Sides::right;
            }

            if (lastSide == Sides::right) {
                if (!isOccupied(leftAdjacent)) {
                    slots[leftAdjacent] = std::move(newEnemy);
                    count++;
                    if (leftAdjacent > 0) {
                        --leftAdjacent;
                    }
                    lastSide = Sides::left;
                }
            } else {
                if (!isOccupied(rightAdjacent)) {
                    slots[rightAdjacent] = std::move(newEnemy);
                    count++;
                    if (rightAdjacent < 4) {
                        ++rightAdjacent;
                    }
                    lastSide = Sides::right;
                }
            }
        }
    }
}

bool EnemyLineup::isOccupied(int iIndex) {
    if (iIndex > 0 && iIndex < NUM_SLOTS) {
        if (slots[static_cast<size_t>(iIndex)] != nullptr) {
            return true;
        } else return false;
    } else return true;
}

void EnemyLineup::displayLineup() {
    std::cout << "Enemy Lineup: " << std::endl;
    for (const auto& slot : slots) {
        if (!slot) {
            std::cout << "  " << "[ ]" << "  ";
        } else {
            std::cout << "  " << slot->getName() << "  ";
        }
    }
}