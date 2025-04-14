#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game_logic.h"
#include "ai.h"

int difficulty = 0;

void playGame(){
    char board[3][3];

    initBoard(board);

    while(true){
        printBoard(board);
        playerPick(board);
        if (checkWin(board, 'X') || isBoardFull(board)){
            break;
        }
        computerPick(board);
        if (checkWin(board, 'O') || isBoardFull(board)){
            break;
        }
    }

    printBoard(board);

    if (checkWin(board, 'X')){
        printf("Player wins!\n");
    }
    else if (checkWin(board, 'O')){
        printf("Computer wins!\n");
    }
    else {
        printf("Draw\n");
    }
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    printf("\n");
    printf("+-------------------------------+\n");
    printf("|          TIC TAC TOE          |\n");
    printf("+-------------------------------+\n");
    printf("\n");

    setDifficulty();  // Set difficulty level for computer

    int opt = 0;
    char input[10];

    // Game loop
    while (1) {
        playGame();

        while(1){
            printf("\n");
            printf("What do you want to do next?\n");
            printf("1. Play again (same difficulty)\n");
            printf("2. Change difficulty\n");
            printf("3. Exit\n");
            printf("Choose an option: ");
            if (fgets(input, sizeof(input), stdin)){  // Securely ask for user input
                if (sscanf(input, "%d", &opt) == 1 && opt >= 1 && opt <= 3){
                    break;
                }
            }
            fprintf(stderr, "Error: Please enter a number between 1 and 3");
        }

        if (opt == 2){
            setDifficulty();
            playGame();
        } else if (opt == 3){
            printf("Thanks for playing!\n");
            break;
        }
    }
    return 0;
}
