#pragma once
#include <string>
#include <utility>

struct BattleContext;

class Enemy;

class Basic{
private:
    std::string name;
    std::string element;

public:
    Basic(std::string basicName, std::string basicElement)
        : name(std::move(basicName)), element(std::move(basicElement)) {}

    virtual ~Basic() = default;
    virtual void useBasic(BattleContext& battleContext) = 0;
};
