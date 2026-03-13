#include "Creature.hpp"

CreatureClass::CreatureClass(string charN, int hp, int maxhp, int def, string wep, map<string, int> mov) 
        : name(charN), health(hp), maxhealth(maxhp), defence(def), wepon(wep), moves(mov) {};

    void CreatureClass::setName(const string& newName) {
        name = newName;
    }

    void CreatureClass::TakeDamage(int damage) {
        // Adds damage to the the player or enemy
        health -= damage;
        if (health < 0) {
            health = 0;
        }
        // cout << name << " takes " << damage << "damage! \n \n";
    }

    void CreatureClass::AddHealing(int healing) {
        // Adds damage to the the player or enemy
        health += healing;
        if (health > maxhealth) {
            health = maxhealth;
        }
        // cout << name << " takes " << healing << "healing! \n";
    }

    // int CreatureClass::getAttack() const {
    //     return attack;
    // }

    int CreatureClass::getMaxHealth() const {
        return maxhealth;
    }

    // void CreatureClass::defend(CreatureClass& player, int defense) {
    //     cout << "You brace yourself, preparing some of the incoming attack\n";
    // }

    // void CreatureClass::useSpecial(CreatureClass& enemy) {
    //     if (specialUses > 0) {
    //         enemy.TakeDamage(30); // special damage
    //         specialUses--;
    //         cout << "Caffeine Crashout used! " << specialUses << " drinks remaining.\n";
    //     } else {
    //         cout << "No caffeinated drinks left!\n";
    //     }
    // }

    // Simple returns, name, health and status
    bool CreatureClass::isAlive() const {return health > 0;}
    string CreatureClass::getName() const {return name;}
    int CreatureClass::getHealth() const {return health;}
