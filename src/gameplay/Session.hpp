#pragma once
#include <vector>
#include "../entities/Character.hpp"
#include "../entities/Enemy.hpp"

class Session {
private:
    std::vector<std::unique_ptr<Character>> characters;
    std::vector<std::unique_ptr<Enemy>> enemies;

public:
    Session(std::vector<std::unique_ptr<Character>> characters_) : characters(std::move(characters_)) {}

    void startSession();
};
