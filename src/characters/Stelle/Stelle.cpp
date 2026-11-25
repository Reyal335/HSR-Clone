#include "Stelle.hpp"

std::unique_ptr<Basic> createStelleBasic();
std::unique_ptr<Skill> createStelleSkill();

Stelle::Stelle(int id_)
    : Character(id_, "Stelle", Path::Destruction, Element::Physical,
                163, 84, 62, 100, 0, 60) {
    basic = createStelleBasic();
    skill = createStelleSkill();
    setGameStats();
}
