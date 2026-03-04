CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

all: test_syntaxtree.out

test_syntaxtree.out: test_syntaxtree.cpp SyntaxTree.cpp SyntaxTree.h
	$(CXX) $(CXXFLAGS) test_syntaxtree.cpp SyntaxTree.cpp -o test_syntaxtree.out

clean:
	rm -f *.out

.PHONY: all clean