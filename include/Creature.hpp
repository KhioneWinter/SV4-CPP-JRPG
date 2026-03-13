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
        int MaxHealing;
        int MaxSpecials;
        vector<pair<int,int>> healingMoves;
        vector<pair<int,int>> specialMoves;
        vector<pair<string, int>> mov;
        
    public: 
        CreatureClass(string charN, int hp, int maxhp, int def, vector<pair<int,int>> healingMoves, vector<pair<int,int>> specialMoves,vector<pair<string, int>> mov);
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
        int specialsTotal() const;
        int healingAmount() const;
        int healingTotal() const;
        pair<string,int> chooseMove() const;
        int getHealingAmount();
        int getSpecialsAmount();
        int specialsAmount() const;
        bool canUseHealing() const;
        void useHealing(CreatureClass& player);
        void addToSpecial();
        void addToHeals();
        void resetHealing();
};
