#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>
#include "Player.hpp"
#include "Enemy.hpp"
using namespace std;

extern bool PLAYERDEAD;  
class BattleCycleClass {
public:
    void cycle(CharacterClass& player, CreatureClass& enemy, int enemyIdx);
    void healthStatus(CreatureClass& player, CreatureClass& enemy);
    void enemyPicture(int enemyIdx);
};