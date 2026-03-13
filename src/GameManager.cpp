#include "GameManager.hpp"

GameManagerClass::GameManagerClass() {
    enemies.push_back(EnemyClass("TEITUR", 100, 100, 100, "Code",{{"Clunk", 4}, {"Special!", 8}}));
    enemies.push_back(EnemyClass("KONRÁÐ", 100, 100, 100, "Code",{{"Clunk", 4}, {"Special!", 8}}));
    enemies.push_back(EnemyClass("ATLI", 100, 100, 100, "Code",{{"Clunk", 4}, {"Special!", 8}}));
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
    addStoryElement("titleScreen.txt");
    cout << "\nPress enter to continue: ";
    cin.ignore(); 

    system("clear");
    addStoryElement("storySetting.txt");

    cout << "\nPress enter to continue: ";
    cin.ignore(); 

    while (!PLAYERDEAD && currentEnemy < (int)enemies.size()-3) {
        nextEnemy();
        BattleCycleClass BCC;
        BCC.cycle(player, enemies[currentEnemy], currentEnemy);
        system("clear");
        addStoryElement("enemyBeaten.txt");
        CharacterClass Player;
        Player.roadChoice();
    }
}

void GameManagerClass::addStoryElement(string filename) {
    ifstream file("txt-files/"+filename);

    string element;

    if (file.is_open() ) {
        while (getline(file, element)) {
            cout << element << endl;
        }

        file.close();
    } 
    else {
        cerr << "Error with file opening" << endl;
    }
}
