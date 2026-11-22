#include "../../../entities/Basic.h++"
#include <string>
#include <iostream>

class FarewellHit : public Basic {
    public:
        FarewellHit() : Basic("Farewell Hit", "Physical") {}

        void useBasic() override {
            std::cout << "Stelle uses Farewell Hit! Performing a basic attack" << std::endl;
        }
};