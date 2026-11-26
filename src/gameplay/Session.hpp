#pragma once
#include <vector>
#include <deque>
#include "../entities/Character.hpp"
#include "../entities/Enemy.hpp"
#include "../entities/EnemyLineup.hpp"
#include "../entities/Entity.hpp"

class EnemyLineup;
class Entity;

class Session {
private:
    std::vector<std::unique_ptr<Character>> characters;
    std::vector<std::unique_ptr<Enemy>> enemies;
    std::vector<std::unique_ptr<EnemyLineup>> waves;

    std::deque<std::unique_ptr<Entity>> entityActionBar;

    size_t waveNow = 0;
    int currentId = 0;


public:
    Session(std::vector<std::unique_ptr<Character>> characters_) : characters(std::move(characters_)) {
        
    }

    void startSession(int nwaves, int enemies);
    void displayActionBar();
};
