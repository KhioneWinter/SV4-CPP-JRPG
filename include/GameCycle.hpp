#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <vector>
#include "Player.hpp"
#include "Enemy.hpp"
using namespace std;

extern bool PLAYERDEAD;  
class BattleCycleClass {
public:
    void cycle(CreatureClass& enemy, vector<CharacterClass>& characters, int enemyIdx);
    void healthStatus(CreatureClass& player, CreatureClass& enemy);
    void enemyPicture(int enemyIdx, int chosenPlayer);
    string checkIfValidInt(string userInput);
};