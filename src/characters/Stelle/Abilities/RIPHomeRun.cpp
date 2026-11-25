#include "../../../entities/Skill.h++"
#include "../../../gameplay/BattleContext.hpp"
#include "../../../entities/CharacterEnums.hpp"

enum class Element;
class BattleContext;

class RIPHomeRun : public Skill {
public:
    RIPHomeRun() : Skill("RIP Home Run", Element::Physical, 1) {}

    void useSkill(BattleContext& battleContext) {

    }
};

std::unique_ptr<RIPHomeRun> createStelleSkill() {
    return std::make_unique<RIPHomeRun>();
}