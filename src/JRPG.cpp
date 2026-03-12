#include "GameManager.hpp"
#include <bits/stdc++.h>
#include <cctype>
using namespace std;

bool PLAYERDEAD = false;  // ✅ defined here once, extern in header

int main() {
    GameManagerClass GMC;
    GMC.run();
    return 0;
}