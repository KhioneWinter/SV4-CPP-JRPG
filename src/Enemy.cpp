#include "Enemy.hpp"
#include <cstdlib>

EnemyClass::EnemyClass(string charN, int hp, int maxhp, int def, vector<pair<string,int>> mov)
    : CreatureClass(charN, hp, maxhp, def, 3, 3, mov) {}  // 3 heals, 3 specials
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