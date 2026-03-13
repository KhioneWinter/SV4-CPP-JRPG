#include "Creature.hpp"

CreatureClass::CreatureClass(string charN, int hp, int maxhp, int def, int heals, int specials, vector<pair<string, int>> mov) 
        : name(charN), health(hp), maxhealth(maxhp), defence(def), healings(heals), specialUses(specials), mov(mov) {};

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

    int CreatureClass::getAttack() const {
        return mov[0].second;
    }

    int CreatureClass::getMaxHealth() const {
        return maxhealth;
    }

    int CreatureClass::getDefence() const {
        return defence;
    }

    string CreatureClass::specialName() const {
        return mov[1].first;
    }

    // void CreatureClass::defend(CreatureClass& player, int defense) {
    //     cout << "You brace yourself, preparing some of the incoming attack\n";
    // }

    bool CreatureClass::canUseSpecial() const {
        return CreatureClass::specialUses > 0;
    }

    void CreatureClass::useSpecial(CreatureClass& enemy) {
        if (specialUses > 0) {
            enemy.TakeDamage(30); // special damage
            specialUses--;
            cout << "Caffeine Crashout used! " << specialUses << " drink remaining.\n";
        } else {
            cout << "No caffeinated drinks left!\n";
        }
    }

    int CreatureClass::specialsLeft() const {
        return specialUses;
    }

    int CreatureClass::specialsTotal() const {
        return specialsTot;
    }

    void CreatureClass::addMaxHealth(int amount) {
        maxhealth += amount;
    }

    void CreatureClass::addAttack(int amount) {
        mov[0].second += amount;
    }

    void CreatureClass::addToSpecial() {
        specialsTot++;
    }

    void CreatureClass::addToHeals() {
        healingsTot++;
    }

    int CreatureClass::healingAmount() const {
        return healings;
    }

    int CreatureClass::healingTotal() const {
        return healingsTot;
    }

    // Simple returns, name, health and status
    void CreatureClass::resetSpecials() { specialUses = specialsTot; }
    void CreatureClass::resetHealing() {healings = healingsTot;}
    bool CreatureClass::isAlive() const {return health > 0;}
    string CreatureClass::getName() const {return name;}
    int CreatureClass::getHealth() const {return health;}
