#pragma once
#include "Creature.hpp"

class EnemyClass : public CreatureClass {
    int position;
public:
    EnemyClass(string charN, int hp, string wep, map<string, int> mov);
};