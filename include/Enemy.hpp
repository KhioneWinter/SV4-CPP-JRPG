#pragma once
#include "Creature.hpp"
#include <vector>

class EnemyClass : public CreatureClass {
    int position;
public:
    EnemyClass(string charN, int hp, int maxhp, int def, vector<pair<int, int>> healingMoves, vector<pair<int, int>> specialsMoves, vector<pair<string, int>> mov);

};