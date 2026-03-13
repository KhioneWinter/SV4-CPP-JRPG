#pragma once
#include "Creature.hpp"

class CharacterClass : public CreatureClass {
    // Player character stats!
    int position;
    int specialUses;
    int defense;
    int attack;

public:
    // Assigning the player character set values
    CharacterClass(string charN, int hp, int maxhp, int def, string wep, vector<pair<string, int>> mov);
    bool canUseSpecial() const;
    void useSpecial(CreatureClass& enemy);
    void resetSpecials();
    void defend(CreatureClass& player, int defense);
    void roadChoice();
    int getAttack();
    int getMaxHealth();
};
