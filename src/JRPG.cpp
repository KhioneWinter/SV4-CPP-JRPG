#include "GameManager.hpp"
#include <bits/stdc++.h>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

bool PLAYERDEAD = false;

int main() {
    srand(static_cast<unsigned int>(time(0))); // seed for the random nr generating
    GameManagerClass GMC;
    GMC.run();
    return 0;
}