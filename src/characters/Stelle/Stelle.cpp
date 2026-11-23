#include "Stelle.hpp"

std::unique_ptr<Basic> createStelleBasic();

Stelle::Stelle()
    : Character("Stelle", Path::Destruction, Element::Physical,
                163, 84, 62, 100, 0, 60) {
    basic = createStelleBasic();
    setGameStats();
}
