#pragma once
#include <deque>
#include <memory>
#include <vector>
#include "../entities/Entity.hpp"
#include "../entities/Character.hpp"
#include "../entities/Enemy.hpp"

class Character;
class Enemy;
class Entity;

class ActionBar {
private:
    std::deque<Entity*> queue;

public:
    void loadQueue(std::vector<std::unique_ptr<Character>>& characters, 
        std::array<std::unique_ptr<Enemy>, 5>& enemies);

    void printQueue();

    const std::deque<Entity*>& getQueue();

    void moveEntities();

};
