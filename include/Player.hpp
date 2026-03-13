#pragma once
#include "Creature.hpp"

class CharacterClass : public CreatureClass {
    // Player character stats!
    int position;
    bool defending;

public:
    // Assigning the player character set values
    CharacterClass(string charN, int hp, int maxhp, int def, string wep, vector<pair<string, int>> mov);
    // bool canUseSpecial() const;
    // void useSpecial(CreatureClass& enemy);

    // void defend(CreatureClass& player, int defense);
    // void roadChoice();
};
