#pragma once

class Entity {
protected: 
    int id;

public:
    Entity(int id_) : id(id_) {}
    int getId();
};