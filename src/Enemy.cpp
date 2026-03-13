#include "Enemy.hpp"

EnemyClass::EnemyClass(string charN, int hp, int maxhp, int def, int heals, int specials, vector<pair<string, int>> mov)
    : CreatureClass(charN, hp, maxhp, def, heals, specials, mov) {};