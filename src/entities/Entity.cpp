#include "Entity.hpp"

int Entity::getId() {
    return id;
}

bool Entity::operator==(const Entity& entity) const {
    return this->id == entity.id;
}

void Entity::takeTurn() {
}