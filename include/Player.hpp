#pragma once
#include "Creature.hpp"

class CharacterClass : public CreatureClass {
    public:
        CharacterClass(string charN, int hp, int maxhp, int def, string wep, vector<pair<string,int>> mov);
    };