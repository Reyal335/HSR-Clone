#include "Session.hpp"
#include "ActionBar.hpp"
#include "../entities/EnemyLineup.hpp"
#include "../enemies/VoidRanger/VoidRanger.hpp"

class EnemyLineup;
class ActionBar;

// Gameplay Loop
void Session::startSession(int nwaves, int nenemies) {

    // Create enemy lineup
    for (int i = 1; i <= nwaves; i++) {
        std::unique_ptr<EnemyLineup> enemyLineup = std::make_unique<EnemyLineup>();
        for (int e = 0; e < nenemies; e++) {
            std::unique_ptr<VoidRanger> voidRanger = std::make_unique<VoidRanger>(currentId);
            enemyLineup->placeEnemy(std::move(voidRanger));
        }
        waves.push_back(std::move(enemyLineup));
    }

    // Create Entity Lineup
    

    // Gameplay loop of session
    for (auto& wave : waves) {
        ActionBar actionBar;
        actionBar.loadQueue(characters, wave->getLineup());
        actionBar.printQueue();
        // Loops until enemy count is 0 for each wave
        // while (wave->getCount() != 0) {

        // }

        wave->displayLineup();
    }
}
