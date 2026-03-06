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

using namespace std;

class CreatureClass {
    // Has all values that both player and enemy share
    protected: 
        int health;
        string name;
        string wepon;
        map<string, int> moves;

    public:
        // Putting the chosen values to be kept
        CreatureClass(int hp, string charN, string wep, map<string, int> mov) 
        : health(hp), name(charN), wepon(wep), moves(mov) {};

    void TakeDamage(int damage) {
        // Adds damage to the the player or enemy
        health -= damage;
        if (health < 0) {
            health = 0;
        }
        cout << name << " takes " << damage << "damage!" << "Current HP: " << health << "\n \n";
    }

    void AddHealing(int healing) {
        // Adds damage to the the player or enemy
        health += healing;
        if (health > 20) { // Hard coded for now
            health = 20;
        }
        cout << name << " takes " << healing << "damage!" << "Current HP: " << health << '\n';
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
        : CreatureClass(20, "Hero", "Sword",{{"Power move", 6}, {"Heal", -5}, {"Slash", 5}, {"Defend", 0}}) {};

};

class EnemyClass : public CreatureClass {
    // Enemy stats!
    int position;

    public:
    // Assigning the enemy set values
    EnemyClass() 
        : CreatureClass(17, "Bad guy!", "Club",{{"Clunk", 4}, {"Special!", 8}}) {};

};

class BattleCycleClass {
    // Keeps cycle going until either playr dies or enemy dies
    public:
        void cycle (CreatureClass& player, CreatureClass & enemy){
            cout << "Battle with " << enemy.getName() << "! \n";
            while (player.getHealth() > 0 && enemy.getHealth() > 0) {
                cout << "---STATS---: \n";
                cout << player.getName() << ": (HP:" << player.getHealth() << ") \n";
                cout << enemy.getName() << ": (HP" << enemy.getHealth() << ") \n \n";
                player.TakeDamage(5);
            }
            if (player.getHealth() == 0) {
                cout << "You died \n";
            }
            else if (enemy.getHealth() == 0){
                cout << "You win! \n";
            }
        }
};

class GameManagerClass {
    // Keeps track of the possition in game
    CharacterClass player;
    EnemyClass enemy;


    // EnemyClass.position = 0;
    // CharacterClass.position = 0;
    public: 
        void run() {
            //
            cout << "Welcome traveler! \n \n" ;
            BattleCycleClass BCC;
            BCC.cycle(player, enemy);
        }
};

int main() {
    // Runs the game
    GameManagerClass GMC;
    GMC.run();
    return 0;
}
