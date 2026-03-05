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
    protected: 
        int health;
        string name;
        string wepon;
        map<string, int> moves;
    
    public:
        CreatureClass(int hp, string charN, string wep, map<string, int> mov) 
        : health(hp), name(charN), wepon(wep), moves(mov) {};

    void TakeDamage(int damage) {
        health -= damage;
        if (health < 0) {
            health = 0;
        }
        cout << name << " takes " << damage << "damage!" << "Current HP: " << health << '\n';
    }

    bool isAlive() const {return health > 0;}
    string getName() const {return name;}
    int getHealth() const {return health;}
};

class CharacterClass : public CreatureClass {
    // Player character stats!
    int position;
    
    public:
    CharacterClass() 
        : CreatureClass(20, "Hero", "Sword",{{"Power move", 6}, {"Heal", -5}, {"Slash", 5}, {"Defend", 0}}) {};

};

class EnemyClass : public CreatureClass {
    // Enemy stats!
    int position;

    public:
    EnemyClass() 
        : CreatureClass(17, "Bad guy!", "Club",{{"Clunk", 4}, {"Special!", 8}}) {};

};


class BattleCycleClass {
    // Keeps cycle going until either playr dies or enemy dies
    public:
        void cycle (CreatureClass& player, CreatureClass & enemy){
            cout << "Battle with " << enemy.getName() << "! \n";
            while (player.getHealth() > 0 && enemy.getHealth() > 0) {
                cout << player.getName() << ": (HP:" << player.getHealth() << ") " << enemy.getName() << ": (HP" << enemy.getHealth() << ")";
                player.TakeDamage(5);
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
            cout << "Welcome traveler! \n" ;
            BattleCycleClass BCC;
            BCC.cycle(player, enemy);
        }
};

int main() {
    GameManagerClass GMC;
    GMC.run();
    return 0;
}
