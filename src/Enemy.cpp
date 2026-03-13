#include "Enemy.hpp"
#include <cstdlib>

EnemyClass::EnemyClass(string charN, int hp, int maxhp, int def, vector<pair<int, int>> healingMoves, vector<pair<int, int>> specialMoves, vector<pair<string, int>> mov)
    : CreatureClass(charN, hp, maxhp, def, healingMoves, specialMoves, mov) {};
    pair<string,int> EnemyClass::chooseMove() const {
        // if health below 30%, 70% chance to heal
        if (health < maxhealth / 3 && rand() % 100 < 70) {
            for (auto &m : mov) {
                if (m.first == "Heal") return m;
            }
        }
        // otherwise random attack
        int index = rand() % mov.size();
        return mov[index];
    }