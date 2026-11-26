#pragma once
#include <cstddef>
#include <iostream>
#include <array>
#include <memory>
#include <string>

class Enemy;

enum class Sides {
    left,
    right
};

class EnemyLineup {
private:
    static constexpr size_t NUM_SLOTS = 5;
    std::array<std::unique_ptr<Enemy>, 5> slots;
    size_t count = 0;

    static constexpr std::size_t defaultIndex = 2;
    // indices adjacent to defaultIncex (middle)
    Sides lastSide = Sides::left;
    std::size_t leftAdjacent = 1;
    std::size_t rightAdjacent = 3;


public: 
    void placeEnemy (std::unique_ptr<Enemy> newEnemy);
    bool isOccupied(int index);
    void displayLineup();
    size_t getCount();

    std::array<std::unique_ptr<Enemy>, 5>& getLineup();
};