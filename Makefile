CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I./include

all: JRPG_tests.out

JRPG_tests.out: JRPG_tests.cpp src/JRPG.cpp src/Creature.cpp src/Player.cpp src/Enemy.cpp src/GameCycle.cpp src/GameManager.cpp
	$(CXX) $(CXXFLAGS) JRPG_tests.cpp src/JRPG.cpp src/Creature.cpp src/Player.cpp src/Enemy.cpp src/GameCycle.cpp src/GameManager.cpp -o JRPG_tests.out

clean:
	rm -f *.out

.PHONY: all clean

#17