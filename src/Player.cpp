#include "Player.hpp"

using namespace std;

CharacterClass::CharacterClass()
    : CreatureClass("Some Mediocre Students", 100, "Sword", {{"Power move", 6}, {"Heal", -5}, {"Slash", 5}, {"Defend", 0}}),
        specialUses(3) { }

    bool CharacterClass::canUseSpecial() const {
        return specialUses > 0;
    }

    void CharacterClass::useSpecial(CreatureClass& enemy) {
        if (specialUses > 0) {
            enemy.TakeDamage(30); // special damage
            specialUses--;
            cout << "Caffeine Crashout used! " << specialUses << " drinks remaining.\n";
        } else {
            cout << "No caffeinated drinks left!\n";
        }
    }

    void CharacterClass::resetSpecials() { specialUses = 3; }

