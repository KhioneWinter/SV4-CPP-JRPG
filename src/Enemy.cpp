#include "Enemy.hpp"

EnemyClass::EnemyClass(string charN, int hp, int maxhp, int def, string wep, vector<pair<string, int>> mov)
    : CreatureClass(charN, hp, maxhp, def, wep, mov) {};
    