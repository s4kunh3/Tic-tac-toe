#include "game_logic.h"
#include <stdio.h>

// Initialize board
void initBoard(char board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Print game board
void printBoard(char board[3][3]) {
    printf("       0   1   2 \n");
    printf(" 0     %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("      ---|---|---\n");
    printf(" 1     %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("      ---|---|---\n");
    printf(" 2     %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

// Win condition
bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; // Row
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // Column
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

// Check if board is full
bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Pick which computer to fight
void setDifficulty() {
    char input[10]; // buffer
    while (true) {
        printf("Set the computer difficulty\n");
        printf("easy = 1   medium = 2   hard = 3\n");
        printf("Value: ");
        if (fgets(input, sizeof(input), stdin)){
            if (sscanf(input, "%d", &difficulty) == 1 && difficulty >= 1 && difficulty <= 3){
                break;
            }
        }
        fprintf(stderr, "Error: Plase enter a number between 1 and 3 \n\n");
    }
}

// Player move
void playerPick(char board[3][3]) {
    int row, col;

    while (true) {
        printf("Enter row (0-2) and column (0-2): ");
        scanf("%d %d", &row, &col);

        if ((row >= 0 && row <= 2) && (col >= 0 && col <= 2)) {
            if (board[row][col] == ' ') {
                board[row][col] = 'X';
                break;
            } else {
                printf("Cell is already taken\n");
            }
        } else {
            printf("Invalid input! Row and column must be between 0 and 2.\n");
        }
    }
}
