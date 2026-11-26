#include "../../../entities/Basic.hpp"
#include <string>
#include <iostream>
#include "../../../entities/Enemy.hpp"
#include "../../../gameplay/BattleContext.hpp"

class VortexLeap : public Basic {

public:
        VortexLeap() : Basic("Vortex Leap", "Physical") {}

        void useBasic(BattleContext& battleContext) override {
            int casterAtk = battleContext.caster.getAtk(); 

            std::cout << "> Void Ranger uses Vortex Leap!" << std::endl;
            std::cout << "> Dealt " << casterAtk << " damage to " << battleContext.currentTarget->getName() << "!";
            battleContext.currentTarget->takeDamage(casterAtk);
        }
};

std::unique_ptr<Basic> createVoidRangerBasic() {
    return std::make_unique<VortexLeap>();
}
