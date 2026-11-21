#pragma once
#include "../../entities/Character.hpp"
#include "Abilities/FarewellHit.cpp"

class Stelle : public Character {
    public:
        Stelle() : Character("Stelle", "Destruction", 
            "Physical", 163, 84, 62, 100, 0) {
                    basic = std::make_unique<FarewellHit>();
                }
};