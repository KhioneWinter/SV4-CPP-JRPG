CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I./include

all: JRPG.out

JRPG.out: src/JRPG.cpp src/Creature.cpp src/Player.cpp src/Enemy.cpp src/GameCycle.cpp src/GameManager.cpp
	$(CXX) $(CXXFLAGS) src/JRPG.cpp src/Creature.cpp src/Player.cpp src/Enemy.cpp src/GameCycle.cpp src/GameManager.cpp -o JRPG.out

clean:
	rm -f *.out

.PHONY: all clean

#17