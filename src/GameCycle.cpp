#include "GameCycle.hpp"

    void BattleCycleClass::cycle(EnemyClass& enemy, vector<CharacterClass>& characters, int enemyIdx){
        system("clear");
        cout << enemy.getName() << " is fast approching!\n";
        cout << "Enemy stats are: Max health: " << enemy.getMaxHealth() << ", Defence: " << enemy.getDefence() << ", Attack: " << enemy.getAttack() << "\n \n"; 
        cout << "Which would you rather choose?\n";
        cout << "1. " << characters[0].getName() << ", Max health: " << characters[0].getMaxHealth() << ", Defence: " << characters[0].getDefence() << ", Attack: " << characters[0].getAttack() << "\n";
        cout << "2. " << characters[1].getName() << ", Max health: " << characters[1].getMaxHealth() << ", Defence: " << characters[1].getDefence() << ", Attack: " << characters[1].getAttack() << "\n";
        cout << "\nChoice: ";
        string chosenPlayer;
        cin >> chosenPlayer;
        while (chosenPlayer != "1" && chosenPlayer != "2") {
            cout << "\nPlease choose 1 or 2: ";
            cin >> chosenPlayer;
        }
        int chosenToPlay = stoi(chosenPlayer) -1;
        CharacterClass& player = characters[chosenToPlay];

        player.resetSpecials();
        enemy.resetSpecials();
        bool playerIsDefending = false;

        while (player.getHealth() > 0 && enemy.getHealth() > 0) {
            system("clear");
            cout << "Battle with " << enemy.getName() << "! \n \n";
            enemyPicture(enemyIdx, chosenToPlay);
            healthStatus(player, enemy);

                string userChoice;
                cout << "What would you like to do? \n";
                cout << "- 1. Heal " << player.healingAmount() << "hp ("<< player.getHealingAmount() << "/" << player.healingTotal()<< ")\n";
                cout << "- 2. Attack " << player.getAttack() << "hp\n";
                cout << "- 3. Special: " + player.specialName() +" "<< player.specialsAmount() << "hp (" << player.getSpecialsAmount() << "/"<< player.specialsTotal() << ")\n";
                cout << "- 4. Defend "<< player.getDefence() <<"hp\n \n";

                getline(cin, userChoice);
                string setChoice = "";

                for (size_t  i = 0; i < userChoice.size(); i++) {
                    if (!isdigit(userChoice[i])) {   
                        setChoice += tolower(userChoice[i]);
                    }
                }

                if (userChoice == "1") {
                    cout << "used healing\n";
                    if (player.canUseHealing()) {
                        player.useHealing(player);
                    } else {
                        cout << "You can't use healing now! Attacking instead\n";
                        enemy.TakeDamage(20);
                    }
                }
                else if (userChoice == "2"){
                    cout << "used attack!\n";
                    enemy.TakeDamage(20);
                }
                else if (userChoice == "3") {
                    if (player.canUseSpecial()) {
                        player.useSpecial(enemy);
                    } else {
                        cout << "You can't use your special right now! Attacking instead\n";
                        enemy.TakeDamage(20);
                    }
                }
                else if (userChoice == "4") {
                    cout << "You brace yourself, preparing for some of the incoming attack!\n";
                    playerIsDefending = true;
                }
                else {
                    enemy.TakeDamage(20);
                }
            pair<string,int> enemyMove = enemy.chooseMove();
            string enemyMoveName = enemyMove.first;
            int enemyMoveDamage = enemyMove.second;

            // Decide if enemy heals or attacks
            if (enemyMoveName == "Heal") {
                enemy.AddHealing(enemyMoveDamage);
                cout << enemy.getName() << " uses " << enemyMoveName << " and heals " << enemyMoveDamage << " HP!\n";
            } else {
                int incoming = enemyMoveDamage;
                if (playerIsDefending) {
                    int reduction = player.getDefence();// or fixed amount like 10
                    incoming -= reduction;
                    if (incoming < 0) incoming = 0;
                    cout << "Defend reduced incoming damage by " << reduction << ".\n";
                    playerIsDefending = false;
                }
                player.TakeDamage(incoming);
                cout << enemy.getName() << " uses " << enemyMoveName << " and deals " << incoming << " damage!\n";
            }
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

        int blockwidth = 10;
        int filledEnemy = (enemy.getHealth() * blockwidth) / enemy.getMaxHealth();
        cout << "🔶 " << enemy.getName() << ": (HP: " ;
        for (int i = 0; i < filledEnemy; i++) {
            if (enemy.getHealth() > enemy.getMaxHealth() * 0.6) {
                cout << "🟩";
            }
            else if (enemy.getHealth() > enemy.getMaxHealth() * 0.3) {
                cout << "🟨";
            }
            else {
                cout << "🟥";
            }
        }
        int grayAmountE;
        grayAmountE = blockwidth - filledEnemy;
        for (int i = 0; i < grayAmountE; i++) {
            cout << "⬛";
        }

        cout << ")                        "; 
        cout << "🔷 " << player.getName() << ": (HP: " ;
        int blockwidth2 = 10;
        int filledplayer = (player.getHealth() * blockwidth2) / player.getMaxHealth();
        for (int i = 0; i < filledplayer; i++) {
            if (player.getHealth() > player.getMaxHealth() * 0.6) {
                cout << "🟩";
            }
            else if (player.getHealth() > player.getMaxHealth() * 0.3) {
                cout << "🟨";
            }
            else {
                cout << "🟥";
            }
        }
        int grayAmountP;
        grayAmountP = blockwidth2 - filledplayer;
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

