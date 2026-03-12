#include "Player.hpp"

using namespace std;

CharacterClass::CharacterClass()
    : CreatureClass("Some Mediocre Students", 100, 100, "Sword", {{"Power move", 6}, {"Heal", -5}, {"Slash", 5}, {"Defend", 0}}),
        specialUses(3), defense(30), attack(20) { }

    bool CharacterClass::canUseSpecial() const {
        return CharacterClass::specialUses > 0;
    }

    void CharacterClass::attackIncrease(){
        cout << "You keep going despite the adversities, you feel stronger than before\n";
        attack += 10;
    }

    void CharacterClass::healthIncrease(){
        cout << "You Make a quick rest stop, you feel healthier than before\n";
        maxhealth += 10;
    }

    void CharacterClass::defend(CreatureClass& player, int defense) {
        // TODO: Tweak defense and ennemies to make this actually worth choosing
        // communicate that player is out of defense
        if (defense > 0) {
            defense -= 10;
            player.AddHealing(10);
            cout << "That was a close one! You let down your defense, and take a deep breath\n";
            }
        else {
            cout << "You don't have it in you to defend anymore\n";
        }
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

