#include "Player.hpp"

using namespace std;


CharacterClass::CharacterClass(string charN, int hp, int maxhp, int def, string wep, vector<pair<string, int>> mov)
    : CreatureClass(charN, hp, maxhp, def, wep, mov){};

    bool CharacterClass::canUseSpecial() const {
        return CharacterClass::specialUses > 0;
    }

    void CharacterClass::roadChoice() {
        std::cout << "\nThe hallway before you reveals a classroom, take a break, or trek on?:\n";
        std::cout << "1. Take a quick break (Increase everyone's max health by 10)\n";
        std::cout << "2. Trek on (Increase everyone's attack by 10)\n";

        std::string choice;
        std::getline(std::cin, choice);

        if (choice == "1") {
            maxhealth += 10;
            AddHealing(120);
            std::cout << "You take a break, you feel much better than before. Max health is now " << maxhealth << ".\n";
        } else if (choice == "2") {
            attack += 10;
            std::cout << "You keep going despite the adversities, you feel stronger than before. Attack power increased to " << attack << ".\n";
        } else {
            std::cout << "Invalid input. You sluggishly continue, nothing has changed. The lights flicker.\n";
        }
    }

    // int CharacterClass::getAttack() const {
    //     return attack;
    // }

    // int CharacterClass::getMaxHealth() const {
    //     return maxhealth;
    // }

    // void CharacterClass::defend(CreatureClass& player, int defense) {
    //     cout << "You brace yourself, preparing for the incoming attack\n";
    // }

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

