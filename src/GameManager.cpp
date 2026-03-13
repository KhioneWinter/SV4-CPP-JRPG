#include "GameManager.hpp"
#include <ctime>

GameManagerClass::GameManagerClass() {
    enemies.push_back(EnemyClass("TEITUR", 120, 120, 10, {{0, 0}}, {{0, 0}}, {{"Computer Bash", 10}, {"Æ, aftur??", 20}}));
    enemies.push_back(EnemyClass("KONRÁÐ", 150, 150, 10, {{1, 20}}, {{1, 20}},{{"PC Smackdown", 10}, {"Skilurðu þetta?!", 20}}));
    enemies.push_back(EnemyClass("ATLI", 200, 200, 10, {{2, 30}}, {{2, 30}},{{"Grade Hammer", 20}, {"Back in my day-", 30}}));
    characters.push_back(CharacterClass("BRYNHILDUR", 120, 120, 30, {{1, 20}}, {{1, 30}},{{"ahahaha", 10}, {"Crunch hour!", 30}}));
    characters.push_back(CharacterClass("SARA", 100, 100, 20, {{1, 20}}, {{1, 40}}, {{"on noo..", 20}, {"Caffiene Crashout!", 40}}));
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
        cout << "\nThe hallway before you reveals a classroom, take a break, or trek on?:\n";
        cout << "1. Take a quick break (Increase everyone's max health by 10)\n";
        cout << "2. Trek on (Increase everyone's attack by 10)\n";

        string choice;
        getline(cin, choice);

        if (choice == "1") {
            characters[0].addMaxHealth(10);
            characters[0].AddHealing(200);
            characters[1].addMaxHealth(10);
            characters[1].AddHealing(200);
            cout << "You take a break, you feel much better than before. Max health is now " << characters[0].getMaxHealth() << "for Sara and " << characters[1].getMaxHealth() << ".\n";
        } else if (choice == "2") {
            characters[0].addAttack(10);
            characters[1].addAttack(10);
            cout << "\nYou keep going despite the adversities, you feel stronger than before. Attack power increased to " << characters[0].getAttack() << " for Sara and " << characters[1].getAttack()<< " for Brynhildur.\n \n";
        } else {
            cout << "Invalid input. You sluggishly continue, nothing has changed. The lights flicker.\n";
        } 


        cout << "You feel inspired!\n";
        cout << "1. Compliment yourself (Increase max healing by 1)\n";
        cout << "2. Dance! (Increase max special by 1)\n";

        string secondChoince;
        getline(cin, secondChoince);

        if (secondChoince == "1") {
            characters[0].addToHeals();
            characters[1].addToHeals();
            characters[0].resetHealing();
            characters[1].resetHealing();
            characters[0].resetSpecials();
            characters[1].resetSpecials();
            cout << "You take a break, you feel much better than before. Max health is now " << characters[0].getMaxHealth() << "for Sara and " << characters[1].getMaxHealth() << ".\n";
        } else if (secondChoince == "2") {
            characters[0].addToSpecial();
            characters[1].addToSpecial();
            characters[0].resetHealing();
            characters[1].resetHealing();
            characters[0].resetSpecials();
            characters[1].resetSpecials();
            cout << "\nYou keep going despite the adversities, you feel stronger than before. Attack power increased to " << characters[0].getAttack() << " for Sara and " << characters[1].getAttack()<< " for Brynhildur.\n \n";
        } else {
            cout << "Invalid input. You sluggishly continue, nothing has changed. The lights flicker.\n";
        } 
        
        cout << "\nPress enter to continue: ";
        cin.ignore(); 
    }
