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

## Compilation and Running the Game!!

# Compile walk through:
```bash
make
```

Then we have 1 executable test file:
- `JRPG_test`

# Run game:
```bash
./JRPG_test.out
```

# Clean compiled files:
```bash
make clean
```

------------------------------------------------

# All the Files Included in the Submission
- **Header files**: `Creature.hpp`, `Enemy.hpp`, `GameCycle.hpp`, `GameManager.hpp`, `JRPG.hpp`, `Player.hpp`
- **Implementation files**: `Creature.cpp`, `Enemy.cpp`, `GameCycle.cpp`, `GameManager.cpp`, 
    `JRPG.cpp`, `Player.cpp`
- **Text files**: `boss0.txt`, `boss1.txt`, `boss2.txt`, `protag.txt`, `storySetting.txt`, `titleScreen.txt`

- **Build system**: `Makefile`
- **Documentation**: `README.md`


Well good luck going over the project! (*/ω＼*) (´▽`ʃ♡ƪ) 
(you could always give us extra points, you know A for effert and all that <( _ _ )>)

---------------------------------------------------