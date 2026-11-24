#include "Session.hpp"
#include <queue>
#include "../entities/EnemyLineup.hpp"
#include "../enemies/VoidRanger/VoidRanger.hpp"

class EnemyLineup;

void Session::startSession(int nwaves, int nenemies) {

    // Create enemy lineup
    for (int i = 1; i <= nwaves; i++) {
        std::unique_ptr<EnemyLineup> enemyLineup = std::make_unique<EnemyLineup>();
        for (int e = 0; e < nenemies; e++) {
            std::unique_ptr<VoidRanger> voidRanger = std::make_unique<VoidRanger>();
            enemyLineup->placeEnemy(std::move(voidRanger));
        }
        waves.push_back(std::move(enemyLineup));
    }

    // Gameplay loop of session
    for (auto& wave : waves) {
        wave->displayLineup();
    }
}
