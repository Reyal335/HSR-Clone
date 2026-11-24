#pragma once
#include <vector>
#include "../entities/Character.hpp"
#include "../entities/Enemy.hpp"
#include "../entities/EnemyLineup.hpp"

class EnemyLineup;


class Session {
private:
    std::vector<std::unique_ptr<Character>> characters;
    std::vector<std::unique_ptr<Enemy>> enemies;
    std::vector<std::unique_ptr<EnemyLineup>> waves;

    size_t waveNow = 0;

public:
    Session(std::vector<std::unique_ptr<Character>> characters_) : characters(std::move(characters_)) {}

    void startSession(int nwaves, int enemies);
};
