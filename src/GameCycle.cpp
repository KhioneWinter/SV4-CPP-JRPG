#include "GameCycle.hpp"


    void BattleCycleClass::cycle(CharacterClass& player, CreatureClass & enemy, int enemyIdx){
        
        while (player.getHealth() > 0 && enemy.getHealth() > 0) {
            system("clear");
            cout << "Battle with " << enemy.getName() << "! \n \n";
            enemyPicture(enemyIdx);
            healthStatus(player, enemy);

                string userChoice;
                cout << "What would you like to do? \n";
                cout << "- 1. Heal \n";
                cout << "- 2. Attack \n";
                cout << "- 3. Caffeine Crashout \n";
                cout << "- 4. Defend  \n \n";

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
                else if (setChoice == "special" || userChoice == "3"|| userChoice == "caffeinecrashout") {
                    if (player.canUseSpecial()) {
                        player.useSpecial(enemy);
                    } else {
                        cout << "You can't use Crashout right now! Attacking instead\n";
                        enemy.TakeDamage(20);
                    }
                }
                else if (setChoice == "defend" || userChoice == "4") {
                    player.defend(player, 30);
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

void BattleCycleClass::enemyPicture(int enemyIdx) {
    ifstream file1("txt-files/boss"+ to_string(enemyIdx) +".txt");
    ifstream file2("txt-files/protag.txt");

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
