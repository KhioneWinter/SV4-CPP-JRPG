#pragma once
#include "Player.hpp"
#include "Enemy.hpp"
#include "GameCycle.hpp"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

extern bool PLAYERDEAD;  // ✅ reference the global, don't redefine it

class GameManagerClass {
    CharacterClass player;
    vector<EnemyClass> enemies;
    int currentEnemy = -1;
public: 
    GameManagerClass();
    void nextEnemy();
    int currEnemy();
    void run();
    void addStorySetting();
    void addTitleScreen();
};