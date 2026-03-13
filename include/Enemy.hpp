#pragma once
#include "Creature.hpp"

class EnemyClass : public CreatureClass {
    int position;
public:
    EnemyClass(string charN, int hp, int maxhp, int def, string wep, map<string, int> mov);
};