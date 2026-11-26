#pragma once

class Entity {
protected: 
    int id;

public:
    Entity(int id_) : id(id_) {}
    int getId();

    bool operator==(const Entity& entity) const;

    virtual~Entity() = default;
    virtual void takeTurn();
};