#pragma once
#include "Creature.hpp"
#include <vector>

class EnemyClass : public CreatureClass {
    int position;
public:
    EnemyClass(string charN, int hp, int maxhp, int def, int heals, int specials, vector<pair<string, int>> mov);
};