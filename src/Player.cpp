#include "Player.hpp"

using namespace std;


CharacterClass::CharacterClass(string charN, int hp, int maxhp, int def, string wep, vector<pair<string,int>> mov)
    : CreatureClass(charN, hp, maxhp, def, 1, 1, mov) {} // hardcoded 1 heal and 1 special, until we buff them

