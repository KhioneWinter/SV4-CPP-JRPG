#pragma once
#include "Creature.hpp"
#include <vector>

class EnemyClass : public CreatureClass {
    int position;
public:
    EnemyClass(string charN, int hp, int maxhp, int def, string wep, vector<pair<string, int>> mov);
    pair<string,int> chooseMove() const;
};