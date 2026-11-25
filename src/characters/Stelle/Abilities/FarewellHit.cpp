#include "../../../entities/Basic.h++"
#include <string>
#include <iostream>
#include "../../../entities/Enemy.hpp"
#include "../../../gameplay/BattleContext.hpp"

class BattleContext;

class StelleFarewellHit : public Basic {

public:
        StelleFarewellHit() : Basic("Farewell Hit", "Physical") {}

        void useBasic(BattleContext& battleContext) override {
            int casterAtk = battleContext.caster.getAtk();

            std::cout << "> Stelle uses Farewell Hit! Hit her bat against " << std::endl;
            std::cout << "> Dealt " << casterAtk << " damage to " << battleContext.currentTarget->getName() << "!";
            battleContext.currentTarget->takeDamage(casterAtk);
        }
};

std::unique_ptr<Basic> createStelleBasic() {
    return std::make_unique<StelleFarewellHit>();
}
