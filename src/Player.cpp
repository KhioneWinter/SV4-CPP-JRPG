#include "Player.hpp"

using namespace std;

// CharacterClass::CharacterClass() : CreatureClass("", 0, 0, 0, "", {}), position(0), specialUses(0), defense(0), attack(0) {}

CharacterClass::CharacterClass(string charN, int hp, int maxhp, int def, string wep, map<string, int> mov)
    : CreatureClass(charN, hp, maxhp, def, wep, mov){};

    bool CharacterClass::canUseSpecial() const {
        return CharacterClass::specialUses > 0;
    }

    void CharacterClass::roadChoice() {
    std::cout << "\nThe hallway before you reveals a classroom, take a break, or keep going?:\n";
    std::cout << "1. Take a quick break (Increase max health by 10)\n";
    std::cout << "2. Trek on (Increase your attack by 10)\n";

    // std::string choice;
    // std::getline(std::cin, choice);

    // if (choice == "1") {
    //     maxhealth += 10;
    //     AddHealing(10);
    //     std::cout << "You take a break, you feel healthier than before. Max health is now " << maxhealth << ".\n";
    // } else if (choice == "2") {
    //     attack += 10;
    //     std::cout << "You keep going despite the adversities, you feel stronger than before. Attack power increased to " << attack << ".\n";
    // } else {
    //     std::cout << "Invalid input. You sluggishly continue, nothing has changed. The lights flicker.\n";
    // }
    }

    

    void CharacterClass::resetSpecials() { specialUses = 3; }

