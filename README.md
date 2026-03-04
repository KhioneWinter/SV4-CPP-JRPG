-----------------------------------------
Students:
- Brynhildur Þorbjörg Þórhallsdóttir 
- Sara Elísabet Jónsdóttir
------------------------------------------

**We implemented an AST using**
- Parseing: Expression/term/factor
- (We just did an assignment fairly similar using them)

**How we understood the functionality, for this project**
# Expression: 
- Imidietly calls term
- After that it checks if the character is a plus, 
    if it is then they call term again and add then together into a node '+' with the terms on each side

# Term:
- Same logic as Expression except we check for '*'

# Factor:
- checks if the character is an integer, also valid for integer of bigger then 9 - (extra points? (o゜▽゜)o☆)
- Then it also checks if the character is '(' as it they then have to call expression until the closing bracket comes along else its an error

**The logic in descrete string logic**
- So we are well aware this isint the perfect implementation of this exmple,
    but its how we understood it while going through the project

# S -> expr (curr char)
# expr -> term | + term
# term -> factor | * factor
# factor -> int | (expr)

# Tada!! ヾ(≧▽≦*)o

------------------------------------------

**What we implemented for our Syntax Tree** 
# main program 50%
- For first part (add imput which will be read and added to file)
    Use : ./test_syntaxtree.out output.txt input.txt
- For second part (use the tree added to output and get result)
    Use : ./test_syntaxtree.out output.txt

- Extra functionality
    - Whitespace insensitivity 5% ✅
    - Error handling 10% (should get more i.m.o) 
    - Extra operations 10% 

-------------------------------------------

## Compilation and Running the code!!

# Compile walk through:
```bash
make
```

Then we have 1 executable test file:
- `test_syntaxtree`

# Run simple unit tests:
```bash
./test_syntaxtree.out
```

# To add chosen input into the program and into a file run:
```bash
./test_syntaxtree.out output.txt input.txt
```

File names can be chosen dont need to be input/output
for example adding 2*3+5 into input.txt

Then:
# To read from the tree file:
```bash
./test_syntaxtree.out output.txt
```

Reads the tree and gives the result from the tree!

# Clean compiled files:
```bash
make clean
```
Need to execute make cleen if you make any changes to the files and want to use make on them again again.

------------------------------------------------

# All the Files Included in the Submission
- **Header files**: `SyntaxTree.h`
- **Implementation files**: `SyntaxTree.cpp`
- **Simple test files**: `test_syntaxtree.cpp`

- **Build system**: `Makefile`
- **Documentation**: `README.md`


Well good luck going over the project! (*/ω＼*) (´▽`ʃ♡ƪ) 
(you could always give us extra points, you know A for effert and all that <( _ _ )>)

---------------------------------------------------