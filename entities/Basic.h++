#pragma once
#include <string>


class Basic{
private:
    std::string name;
    std::string element;

public:
    Basic(std::string basicName, std::string basicElement)
        : name(std::move(basicName)), element(std::move(basicElement)) {}

    virtual ~Basic() = default;
    virtual void useBasic() = 0;
};