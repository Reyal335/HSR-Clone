#include "../../../entities/Basic.h++"
#include <string>
#include <iostream>
#include "../../../entities/Enemy.hpp"

class VortexLeap : public Basic {

public:
        VortexLeap() : Basic("Vortex Leap", "Physical") {}

        void useBasic(int atk, Enemy& enemy) override {
            std::cout << "> Void Ranger uses Vortex Leap!" << std::endl;
            std::cout << "> Dealt " << atk << " damage to " << enemy.getName() << "!";
            enemy.takeDamage(atk);
        }
};

std::unique_ptr<Basic> createVoidRangerBasic() {
    return std::make_unique<VortexLeap>();
}
