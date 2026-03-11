// Need to use Interface Abstraction for the project
// so one of: Inheretance, templates, variants

// Making a Japanese roleplaying game
// turn based battle and overworld travel

// Each character can perform an action (attack, defend or other special actions, such as healing)
// POLYMORPHISM in code is required

// implement a turn based battle system

// pseudo-randomisation is STRONGLY RECOMENDED

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cctype>

using namespace std;

bool PLAYERDEAD = false;

class CreatureClass {
    // Has all values that both player and enemy share
    protected: 
        string name;
        int health;
        string wepon;
        map<string, int> moves;

    public:
        // Putting the chosen values to be kept
        CreatureClass(string charN, int hp, string wep, map<string, int> mov) 
        : name(charN), health(hp), wepon(wep), moves(mov) {};

    void setName(const string& newName) {
        name = newName;
    }

    void TakeDamage(int damage) {
        // Adds damage to the the player or enemy
        health -= damage;
        if (health < 0) {
            health = 0;
        }
        // cout << name << " takes " << damage << "damage! \n \n";
    }

    void AddHealing(int healing) {
        // Adds damage to the the player or enemy
        health += healing;
        if (health > 100) { // Hard coded for now
            health = 100;
        }
        // cout << name << " takes " << healing << "healing! \n";
    }


    // Simple returns, name, health and status
    bool isAlive() const {return health > 0;}
    string getName() const {return name;}
    int getHealth() const {return health;}
};

class CharacterClass : public CreatureClass {
    // Player character stats!
    int position;
    
    public:
    // Assigning the player character set values
    CharacterClass() 
        : CreatureClass("Some Mediocre Students", 100, "Sword",{{"Power move", 6}, {"Heal", -5}, {"Slash", 5}, {"Defend", 0}}) {};

};

class EnemyClass : public CreatureClass {
    // Enemy stats!
    int position;

    public:
    // Assigning the enemy set values
        EnemyClass(string charN, int hp, string wep, map<string, int> mov) 
            : CreatureClass(charN, hp, wep, mov) {};
};

class BattleCycleClass {
    // Keeps cycle going until either playr dies or enemy dies
    public:
        void cycle (CreatureClass& player, CreatureClass & enemy, int enemyIdx){
            
            while (player.getHealth() > 0 && enemy.getHealth() > 0) {
                system("clear");
                cout << "Battle with " << enemy.getName() << "! \n";
                enemyPicture(enemyIdx);
                healthStatus(player, enemy);

                    string userChoice;
                    cout << "What would you like to do? \n";
                    cout << "- 1. Heal \n";
                    cout << "- 2. Attack \n";
                    cout << "- 3. Special \n \n";

                    getline(cin, userChoice);
                    string setChoice = "";

                    
                    for (size_t  i = 0; i < userChoice.size(); i++) {
                        if (!isdigit(userChoice[i])) {   // ✅ check each character individually
                            setChoice += tolower(userChoice[i]);
                        }
                    }

                    // Trim any spaces from setChoice
                    setChoice.erase(remove(setChoice.begin(), setChoice.end(), ' '), setChoice.end());


                    if (setChoice == "heal" || userChoice == "1") {
                        player.AddHealing(40);
                    }
                    else if (setChoice == "attack" || userChoice == "2"){
                        enemy.TakeDamage(20);
                    }
                    else if (setChoice == "special" || userChoice == "3") {
                        enemy.TakeDamage(30);
                    }
                    else {
                        enemy.TakeDamage(20);
                    }
                player.TakeDamage(10);
        }

    if (enemy.getHealth() == 0) {
        player.AddHealing(100);
        cout << "You win! \n";
    }
    else if (player.getHealth() == 0){
        PLAYERDEAD = true;
        cout << "You died \n";
    }
}

    void healthStatus(CreatureClass& player, CreatureClass & enemy) {

            cout << "\n-------------------------------------------------- | STATS | ------------------------------------------------------------\n";

            cout << "🔶 " << enemy.getName() << ": (HP: " ;
            for (int i = 0; i < (enemy.getHealth() / 10); i++) {
                if (enemy.getHealth() > 50) {
                    cout << "🟩";
                }
                else if (enemy.getHealth() > 25) {
                    cout << "🟨";
                }
                else {
                    cout << "🟥";
                }
            }
            int grayAmountE;
            grayAmountE = 10 - (enemy.getHealth() / 10);
            for (int i = 0; i < grayAmountE; i++) {
                cout << "⬛";
            }

            cout << ")                        "; 
            cout << "🔷 " << player.getName() << ": (HP: " ;
            for (int i = 0; i < (player.getHealth() / 10); i++) {
                if (player.getHealth() > 50) {
                    cout << "🟩";
                }
                else if (player.getHealth() > 25) {
                    cout << "🟨";
                }
                else {
                    cout << "🟥";
                }
            }
            int grayAmountP;
            grayAmountP = 10 - (player.getHealth() / 10);
            for (int i = 0; i < grayAmountP; i++) {
                cout << "⬛";
            }
            cout << ")\n";
        cout << "-------------------------------------------------------------------------------------------------------------------------\n \n";
    }

    void enemyPicture(int enemyIdx) {
        ifstream file1("boss"+ to_string(enemyIdx) +".txt");
        ifstream file2("protag.txt");

        string boss;
        string protag;

        if (file1.is_open() && file2.is_open()) {
            while (getline(file1, boss) && getline(file2, protag)) {
                cout << boss << "           " << protag << endl;
            }

            file1.close();
            file2.close();
        } 
        else {
            cerr << "Error with file opening" << endl;
        }
    }
};

class GameManagerClass {
    // Keeps track of the possition in game
    CharacterClass player;
    vector<EnemyClass> enemies;
    int currentEnemy = -1;

    public: 
        GameManagerClass() {
            enemies.push_back(EnemyClass("TEITUR", 100, "Club",{{"Clunk", 4}, {"Special!", 8}}));
            enemies.push_back(EnemyClass("KONRÁÐ", 100, "Club",{{"Clunk", 4}, {"Special!", 8}}));
            enemies.push_back(EnemyClass("ATLI", 100, "Club",{{"Clunk", 4}, {"Special!", 8}}));
        }

        void nextEnemy() {
            currentEnemy++;
        }

        int currEnemy() {
            return currentEnemy;
        }

        void run() {
            // Runs the game
            system("clear");
            addTitleScreen();

            cout << "\nWelcome traveler! \n \n";

            cout << "Press enter to continue: ";
            cin.ignore(); 

            // cout << "Please enter your name: ";
            // string name;
            // getline(cin, name);
            // if (name != "") {
            //     player.setName(name);
            //     cout << "\n";
            // }

            system("clear");
            addStorySetting();

            cout << "\nPress enter to continue: ";
            cin.ignore(); 
            while (!PLAYERDEAD && currentEnemy < (int)enemies.size()-1) {
                nextEnemy();
                BattleCycleClass BCC;
                BCC.cycle(player, enemies[currentEnemy], currentEnemy);
            }
        }
    
    void addStorySetting() {
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

    void addTitleScreen() {
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
};

int main() {
    // Runs the game
    GameManagerClass GMC;
    GMC.run();
    return 0;
}
