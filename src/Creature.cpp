#include "Creature.hpp"

CreatureClass::CreatureClass(string charN, int hp, int maxhp, string wep, map<string, int> mov) 
        : name(charN), health(hp), maxhealth(maxhp), wepon(wep), moves(mov) {};

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

    // Simple returns, name, health and status
    bool CreatureClass::isAlive() const {return health > 0;}
    string CreatureClass::getName() const {return name;}
    int CreatureClass::getHealth() const {return health;}
