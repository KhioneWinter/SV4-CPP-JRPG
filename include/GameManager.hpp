#pragma once
#include "Player.hpp"
#include "Enemy.hpp"
#include "GameCycle.hpp"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

extern bool PLAYERDEAD;  

class GameManagerClass {
    vector<EnemyClass> enemies;
    vector<CharacterClass> characters;
    int currentEnemy = -1;
public: 
    GameManagerClass();
    void nextEnemy();
    int currEnemy();
    void run();
    void addStoryElement(string filename);
};