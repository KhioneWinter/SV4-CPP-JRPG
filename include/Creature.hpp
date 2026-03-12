#pragma once
#include <string>
#include <map>
#include <iostream>

using std::string;
using std::map;

class CreatureClass {
    // Has all values that both player and enemy share
    protected:
        string name;
        int health;
        int maxhealth;
        string wepon;
        map<string, int> moves;
    public: 
        CreatureClass(string charN, int hp, string wep, map<string, int> mov);
        void TakeDamage(int amount);
        void AddHealing(int healing);
        void setName(const string& newName);
        bool isAlive() const;
        string getName() const;
        int getHealth() const;
        int getMaxHealth() const;
};
