#include "Enemy.hpp"

EnemyClass::EnemyClass(string charN, int hp, string wep, map<string, int> mov)
    : CreatureClass(charN, hp, wep, mov) {}