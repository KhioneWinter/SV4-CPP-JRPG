CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

all: JRPG_tests.out

JRPG_tests.out: JRPG_tests.cpp JRPG.cpp JRPG.h
	$(CXX) $(CXXFLAGS) JRPG_tests.cpp JRPG.cpp -o JRPG_tests.out

clean:
	rm -f *.out

.PHONY: all clean

#17