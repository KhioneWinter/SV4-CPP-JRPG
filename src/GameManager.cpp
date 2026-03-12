#include "GameManager.hpp"

GameManagerClass::GameManagerClass() {
    enemies.push_back(EnemyClass("TEITUR", 100, "Code",{{"Clunk", 4}, {"Special!", 8}}));
    enemies.push_back(EnemyClass("KONRÁÐ", 100, "Code",{{"Clunk", 4}, {"Special!", 8}}));
    enemies.push_back(EnemyClass("ATLI", 100, "Code",{{"Clunk", 4}, {"Special!", 8}}));
}

void GameManagerClass::nextEnemy() {
    currentEnemy++;
}

int GameManagerClass::currEnemy() {
    return currentEnemy;
}

void GameManagerClass::run() {
    // Runs the game
    system("clear");
    // addTitleScreen();

    // cout << "\nPress enter to continue: ";
    // cin.ignore(); 

    // cout << "Please enter your name: ";
    // string name;
    // getline(cin, name);
    // if (name != "") {
    //     player.setName(name);
    //     cout << "\n";
    // }

    // system("clear");
    // addStorySetting();

    // cout << "\nPress enter to continue: ";
    // cin.ignore(); 

    while (!PLAYERDEAD && currentEnemy < (int)enemies.size()-1) {
        nextEnemy();
        BattleCycleClass BCC;
        BCC.cycle(player, enemies[currentEnemy], currentEnemy);
    }
}

void GameManagerClass::addStorySetting() {
    ifstream file("storySetting.txt");

    string story;

    if (file.is_open() ) {
        while (getline(file, story)) {
            cout << story << endl;
        }

        file.close();
    } 
    else {
        cerr << "Error with file opening" << endl;
    }
}

void GameManagerClass::addTitleScreen() {
    ifstream file("titlescreen.txt");

    string title;

    if (file.is_open() ) {
        while (getline(file, title)) {
            cout << title << endl;
        }

        file.close();
    } 
    else {
        cerr << "Error with file opening" << endl;
    }
}