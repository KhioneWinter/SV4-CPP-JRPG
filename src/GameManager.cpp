#include "GameManager.hpp"
#include <ctime>

GameManagerClass::GameManagerClass() {
    enemies.push_back(EnemyClass("TEITUR", 120, 120, 10, "Code",{{"Computer Bash", 10}, {"Hvernig fórstu að þessu??", 20}}));
    enemies.push_back(EnemyClass("KONRÁÐ", 150, 150, 10, "Code",{{"PC Smackdown", 10}, {"Skilurðu þetta?!", 20},{"All Nighter", 30}}));
    enemies.push_back(EnemyClass("ATLI", 200, 200, 10, "Code",{{"Grade Hammer", 20}, {"Back in my day-", 30}, {"All Weeker", 30}}));
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
    system("clear");
    while (currentEnemy < (int)enemies.size()-1) {
        nextEnemy();
        BattleCycleClass BCC;
        BCC.cycle(enemies[currentEnemy], characters, currentEnemy);
        if (PLAYERDEAD) {
            system("clear");
            addStoryElement("badEnd.txt");
            cout << "\nPress enter to quit: ";
            cin.ignore(); 
            break;
        }
        if (currentEnemy == (int)enemies.size()-1) {
            addStoryElement("goodEnd.txt");
        }
        else {
            system("clear");
            addStoryElement("enemyBeaten.txt");
            cout << "\n";
            roadChoice();
        }
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
            std::cout << "You keep going despite the adversities, you feel stronger than before. Attack power increased to " << characters[0].getAttack() << " for Sara and " << characters[1].getAttack()<< " for Brynhildur.\n";
        } else {
            std::cout << "Invalid input. You sluggishly continue, nothing has changed. The lights flicker.\n";
        } 
        cout << "\nPress enter to continue: ";
        cin.ignore(); 
    }
