# Tic Tac Toe

## How to execute it
On the terminal run make, that should compile all c files, if you dont want to pollute you folder then you can run make clean, which removes the compiled files to keep the project file clean.

```bash
    make
```

then run 

```bash
    ./tic-tac-toe
```

if you want to delete the executable do

```bash
    make clean
```


## Gameplay

Now for the gameplay loop, here is the important info:

### Difficulty

When you start the game is going to introduce you and then make you pick the difficulty.

- Difficulty 1: The computer just picks a random spot on the board.

- Difficulty 2: The computer simulates some scenarious, trying to pick a winning space or trying to block the player, if it can't do any then it picks a random space in the board. 

- Difficulty 3: The computer uses the minimax algorithm, making it almost unbeatable, good luck :)

### Board

The board is a simple 3x3 tic-tac-toe board. You will be prompted to pick the area of the board in which you will place your ' X '. Example:

```bash
    Enter row (0-2) and column (0-2): 0 1

           0   1   2 
     0       | X |   
          ---|---|---
     1       |   |   
          ---|---|---
     2       |   |   
```

Then the computer will make its move >:)

### Game Over

The conditions for a game over are:

- The player or computer achieve a line.

- The board gets full

