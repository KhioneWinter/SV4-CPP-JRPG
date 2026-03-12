#pragma once
#include "Creature.hpp"

class CharacterClass : public CreatureClass {
    // Player character stats!
    int position;
    int specialUses;

public:
    // Assigning the player character set values
    CharacterClass();
    bool canUseSpecial() const;
    void useSpecial(CreatureClass& enemy);
    void resetSpecials();
};
