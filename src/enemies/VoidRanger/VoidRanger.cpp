#include "VoidRanger.hpp"

std::unique_ptr<Basic> createVoidRangerBasic();

VoidRanger::VoidRanger()
    : Enemy("Void Ranger", Element::Physical, 163, 84, 62, 100, 0, 60) {
    basic = createVoidRangerBasic();
    setGameStats();
}
