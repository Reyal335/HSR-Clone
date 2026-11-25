#pragma once
#include <vector>
#include <string>
#include "Cursor.hpp"
#include "../entities/Enemy.hpp"
#include "../entities/Character.hpp"
#include "../entities/EnemyLineup.hpp"

class Enemy;
class Character;
class EnemyLineup;

struct BattleContext {
    Character& caster;

    Character* primaryAllyTarget = nullptr;
    Enemy* currentTarget = nullptr;

    EnemyLineup& allEnemies;
    std::vector<Character&> allAllies;

    /**  Cursor - Goes 0-4, Default -> [2]
                     V
        []  [o]  ([O])  [o]  []
                        v  
        []  []  []  [o]  ([O]) **/
    size_t cursor = 2;

};

