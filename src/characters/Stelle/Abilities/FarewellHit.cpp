#include "../../../entities/Basic.h++"
#include <string>
#include <iostream>
#include "../../../entities/Enemy.hpp"

class StelleFarewellHit : public Basic {

public:
        StelleFarewellHit() : Basic("Farewell Hit", "Physical") {}

        void useBasic(int atk, Enemy& enemy) override {
            std::cout << "> Stelle uses Farewell Hit! Hit her bat against " << std::endl;
            std::cout << "> Dealt " << atk << " damage to " << enemy.getName() << "!";
            enemy.takeDamage(atk);
        }
};

std::unique_ptr<Basic> createStelleBasic() {
    return std::make_unique<StelleFarewellHit>();
}
