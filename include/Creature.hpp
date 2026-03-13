#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <utility> 

using namespace std;

class CreatureClass {
    protected:
        string name;
        int health;
        int maxhealth;
        int defence;
        int healings;
        int specialUses;
        int healingsTot;
        int specialsTot;
        vector<pair<string, int>> mov;

    public:
        CreatureClass(string charN, int hp, int maxhp, int def, int heals, int specials, vector<pair<string,int>> mov);
        void TakeDamage(int amount);
        void AddHealing(int healing);
        void setName(const string& newName);
        bool isAlive() const;
        string getName() const;
        int getHealth() const;
        int getMaxHealth() const;
        int getDefence() const;
        int getAttack() const;
        void useSpecial(CreatureClass& enemy);
        string specialName() const;
        bool canUseSpecial() const;
        void resetSpecials();
        void addMaxHealth(int amount);
        void addAttack(int amount);
        void addToSpecial();
        void addToHeals();
        void resetHealing();
        int specialsLeft() const;
        int specialsTotal() const;
        int healingAmount() const;
        int healingTotal() const;
    };