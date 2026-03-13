#include "GameManager.hpp"

GameManagerClass::GameManagerClass() {
    enemies.push_back(EnemyClass("TEITUR", 120, 120, 10, "Code",{{"Ahahahahaaa", 10}, {"Æ, aftur??", 20}}));
    enemies.push_back(EnemyClass("KONRÁÐ", 150, 150, 10, "Code",{{"Wrahh", 10}, {"Skilurðu þetta?!", 20}}));
    enemies.push_back(EnemyClass("ATLI", 200, 200, 10, "Code",{{"UGhhhhh", 20}, {"Back in my day-", 30}}));
    characters.push_back(CharacterClass("BRYNHILDUR", 120, 120, 30, "Code",{{"ahahaha", 10}, {"Crunch hour!", 20}}));
    characters.push_back(CharacterClass("SARA", 100, 100, 20, "Code",{{"on noo..", 20}, {"Caffiene Crashout!", 30}}));
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
        BCC.cycle(enemies[currentEnemy], characters, currentEnemy);
        system("clear");
        addStoryElement("enemyBeaten.txt");
        // CharacterClass PlayerChoice;
        // PlayerChoice.roadChoice();
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
