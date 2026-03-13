#include "Player.hpp"

using namespace std;


CharacterClass::CharacterClass(string charN, int hp, int maxhp, int def, int heals, int specials, vector<pair<string, int>> mov)
    : CreatureClass(charN, hp, maxhp, def, heals, specials, mov){};

