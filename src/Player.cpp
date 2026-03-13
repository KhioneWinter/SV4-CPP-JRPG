#include "Player.hpp"

using namespace std;


CharacterClass::CharacterClass(string charN, int hp, int maxhp, int def, vector<pair<int, int>> healingMoves, vector<pair<int, int>> specialMoves, vector<pair<string, int>> mov)
    : CreatureClass(charN, hp, maxhp, def, healingMoves, specialMoves, mov) {};




