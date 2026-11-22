#pragma once
#include "../../entities/Character.hpp"
#include "../../entities/Enums.hpp"
#include "Abilities/FarewellHit.cpp"

class Stelle : public Character {
    public:
        Stelle() : Character("Stelle", Path::Destruction, 
            Element::Physical, 163, 84, 62, 100, 0, 60) {
                    basic = std::make_unique<FarewellHit>();
                }
};