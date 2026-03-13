#include "GameManager.hpp"

GameManagerClass::GameManagerClass() {
    enemies.push_back(EnemyClass("TEITUR", 100, 100, 100, "Code",{{"Ahahahahaaa", 4}, {"In my day-", 8}}));
    enemies.push_back(EnemyClass("KONRÁÐ", 100, 100, 100, "Code",{{"Wrahh", 4}, {"Special!", 8}}));
    enemies.push_back(EnemyClass("ATLI", 100, 100, 100, "Code",{{"UGhhhhh", 4}, {"Special!", 8}}));
    characters.push_back(CharacterClass("BRYNHILDUR", 120, 120, 100, "Code",{{"ahahaha", 4}, {"Crunch hour!", 20}}));
    characters.push_back(CharacterClass("SARA", 100, 100, 100, "Code",{{"on noo..", 4}, {"Caffiene Crashout!", 30}}));
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

    while (!PLAYERDEAD && currentEnemy < (int)enemies.size()-1) {
        nextEnemy();
        BattleCycleClass BCC;
        BCC.cycle(enemies[currentEnemy], characters, currentEnemy);
        system("clear");
        addStoryElement("enemyBeaten.txt");
        cout << "\n";
        roadChoice();
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


void GameManagerClass::roadChoice() {
        std::cout << "\nThe hallway before you reveals a classroom, take a break, or trek on?:\n";
        std::cout << "1. Take a quick break (Increase everyone's max health by 10)\n";
        std::cout << "2. Trek on (Increase everyone's attack by 10)\n";

        std::string choice;
        std::getline(std::cin, choice);

        if (choice == "1") {
            characters[0].addMaxHealth(10);
            characters[0].AddHealing(200);
            characters[1].addMaxHealth(10);
            characters[1].AddHealing(200);
            std::cout << "You take a break, you feel much better than before. Max health is now " << characters[0].getMaxHealth() << "for Sara and " << characters[1].getMaxHealth() << ".\n";
        } else if (choice == "2") {
            characters[0].addAttack(10);
            characters[1].addAttack(10);
            std::cout << "You keep going despite the adversities, you feel stronger than before. Attack power increased to " << characters[0].getAttack() << "for Sara and " << characters[1].getAttack()<< ".\n";
        } else {
            std::cout << "Invalid input. You sluggishly continue, nothing has changed. The lights flicker.\n";
        } 
    }
