#include "Creature.hpp"

CreatureClass::CreatureClass(string charN, int hp, int maxhp, int def, vector<pair<int,int>> healMov, vector<pair<int,int>> specMov, vector<pair<string, int>> mov) 
        : name(charN), health(hp), maxhealth(maxhp), defence(def), healingMoves(healMov), specialMoves(specMov), mov(mov) {
    MaxHealing = healingMoves[0].first;
    MaxSpecials = specialMoves[0].first;
};

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

    int CreatureClass::getHealingAmount() {
        return healingMoves[0].first;
    }

    int CreatureClass::getSpecialsAmount() {
        return specialMoves[0].first;
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
        return specialMoves[0].first > 0;
    }

    bool CreatureClass::canUseHealing() const {
        return healingMoves[0].first > 0;
    }

    void CreatureClass::useSpecial(CreatureClass& enemy) {
        if (specialMoves[0].first > 0) {
            enemy.TakeDamage(30); 
            specialMoves[0].first--;
            cout << "Caffeine Crashout used! " << specialMoves[0].first << " drinks remaining.\n";
        } else {
            cout << "No caffeinated drinks left!\n";
        }
    }

    void CreatureClass::useHealing(CreatureClass& player) {
        if (healingMoves[0].first > 0) {
            player.AddHealing(healingMoves[0].second);
            healingMoves[0].first--;
            cout << "Healing used! \n";
        } else {
            cout << "No healing left!\n";
        }
    }

    int CreatureClass::specialsTotal() const {
        return MaxSpecials;
    }

    void CreatureClass::addMaxHealth(int amount) {
        maxhealth += amount;
    }

    void CreatureClass::addAttack(int amount) {
        mov[0].second += amount;
    }

    void CreatureClass::addToSpecial() {
        MaxSpecials++;
        specialMoves[0].first++;
    }
    void CreatureClass::addToHeals() {
        MaxHealing++;
        healingMoves[0].first++;
    }

    int CreatureClass::healingAmount() const {
        return healingMoves[0].second;
    }

    int CreatureClass::specialsAmount() const {
        return specialMoves[0].second;
    }

    int CreatureClass::healingTotal() const {
        return MaxHealing;
    }

    void CreatureClass::defend() {
        cout << "You brace yourself, preparing for some of the incoming attack\n";
    }

    // Simple returns, name, health and status
    void CreatureClass::resetSpecials() { specialMoves[0].first = MaxSpecials; }
    void CreatureClass::resetHealing() {healingMoves[0].first = MaxHealing;}
    void CreatureClass::resetHealth() { health = maxhealth; }
    bool CreatureClass::isAlive() const {return health > 0;}
    string CreatureClass::getName() const {return name;}
    int CreatureClass::getHealth() const {return health;}
