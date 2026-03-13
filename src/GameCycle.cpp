#include "GameCycle.hpp"


    void BattleCycleClass::cycle(CreatureClass& enemy, vector<CharacterClass>& characters, int enemyIdx){
        system("clear");
        cout << enemy.getName() << " is fast approching!\n";
        cout << "Enemy stats are: Max health: " << enemy.getMaxHealth() << ", Defence: " << enemy.getDefence() << ", Attack: " << enemy.getAttack() << "\n \n"; 
        cout << "Which would you rather choose?\n";
        cout << "1. " << characters[0].getName() << ", Max health: " << characters[0].getMaxHealth() << ", Defence: " << characters[0].getDefence() << ", Attack: " << characters[0].getAttack() << "\n"; //  
        cout << "2. " << characters[1].getName() << ", Max health: " << characters[1].getMaxHealth() << ", Defence: " << characters[1].getDefence() << ", Attack " << characters[1].getAttack() << "\n";
        cout << "\nChoice: ";
        string chosenPlayer;
        cin >> chosenPlayer;
        while (chosenPlayer != "1" && chosenPlayer != "2") {
            cout << "\nPlease choose 1 or 2: ";
            cin >> chosenPlayer;
        }
        int chosenToPlay = stoi(chosenPlayer) -1;
        CharacterClass& player = characters[chosenToPlay];

        while (player.getHealth() > 0 && enemy.getHealth() > 0) {
            system("clear");
            cout << "Battle with " << enemy.getName() << "! \n \n";
            enemyPicture(enemyIdx, chosenToPlay);
            healthStatus(player, enemy);

                string userChoice;
                cout << "What would you like to do? \n";
                cout << "- 1. Heal ("<< player.healingAmount() << "/" << player.healingTotal()<< ")\n";
                cout << "- 2. Attack\n";
                cout << "- 3. " + player.specialName() +" (" << player.specialsLeft() << "/"<< player.specialsTotal() << ")\n";
                cout << "- 4. Defend\n \n";

                getline(cin, userChoice);
                string setChoice = "";

                for (size_t  i = 0; i < userChoice.size(); i++) {
                    if (!isdigit(userChoice[i])) {   
                        setChoice += tolower(userChoice[i]);
                    }
                }

                if (userChoice == "1") {
                    player.AddHealing(40);
                }
                else if (userChoice == "2"){
                    enemy.TakeDamage(20);
                }
                else if (userChoice == "3") {
                    if (player.canUseSpecial()) {
                        player.useSpecial(enemy);
                    } else {
                        cout << "You can't use Crashout right now! Attacking instead\n";
                        enemy.TakeDamage(20);
                    }
                }
                else if (userChoice == "4") {
                    
                    // player.defend();
                }
                else {
                    enemy.TakeDamage(20);
                }
            player.TakeDamage(20);
    }

    if (enemy.getHealth() == 0) {
        player.AddHealing(200);
        cout << "You win! \n";
    }
    else if (player.getHealth() == 0){
        PLAYERDEAD = true;
        cout << "You died \n";
    }
}

void BattleCycleClass::healthStatus(CreatureClass& player, CreatureClass & enemy) {

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

void BattleCycleClass::enemyPicture(int enemyIdx, int chosenPlayer) {
    ifstream file1("txt-files/boss"+to_string(enemyIdx)+".txt");
    ifstream file2("txt-files/protag"+to_string(chosenPlayer)+".txt");

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

