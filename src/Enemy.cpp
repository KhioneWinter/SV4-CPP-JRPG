#include "Enemy.hpp"

EnemyClass::EnemyClass(string charN, int hp, int maxhp, string wep, map<string, int> mov)
    : CreatureClass(charN, hp, maxhp, wep, mov) {};