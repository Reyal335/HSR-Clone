#include "VoidRanger.hpp"

std::unique_ptr<Basic> createVoidRangerBasic();

VoidRanger::VoidRanger(int id_)
    : Enemy(id_, "Void Ranger", Element::Physical, 163, 84, 62, 95, 0, 60) {
    basic = createVoidRangerBasic();
    setGameStats();
}
