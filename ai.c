#include "ai.h"
#include "game_logic.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Picks a random empty space in the board
void easyComputer(char board[3][3]) {
	int row, col;
	do {
		row = rand() % 3;
		col = rand() % 3;
	} while(board[row][col] != ' ');
	board[row][col] = 'O';
	printf("Computer choice: %d %d\n", row, col);
}

// Actively tries to win and to block the player
void mediumComputer(char board[3][3]) {
	int row, col;

    // Try to get a win scenario
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                if (checkWin(board, 'O')){
                    printf("Computer choice: %d %d\n", i, j);
                    return;
                }
                board[i][j] = ' '; // if no win, undo move
            }
        }
    }

    // Try to block player
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'X';
                if (checkWin(board, 'X')) {
                    board[i][j] = 'O';
                    printf("Computer choice: %d %d\n", i, j);
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    // If no win/block scenario then pick a random space
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');

    board[row][col] = 'O';
    printf("Computer choice: %d %d\n", row, col);
}

// Minimax algorithm
// Guide: neverstopbuilding.com/blog/minimax

int minimax(char board[3][3], bool isMaximizing){
    if (checkWin(board, 'O')) return +10;
    if (checkWin(board, 'X')) return -10;
    if (isBoardFull(board)) return 0;

    int bestScore = isMaximizing ? -1000 : 1000;

    for (int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if (board[i][j] == ' '){
                board[i][j] = isMaximizing ? 'O' : 'X';
                int score = minimax(board, !isMaximizing);
                board[i][j] = ' ';
                if (isMaximizing){
                    if (score > bestScore){
                        bestScore = score;
                    }
                } else {
                    if (score < bestScore){
                        bestScore = score;
                    }
                }
            }
        }
    }
    return bestScore;
}

void hardComputer(char board[3][3]){
    int bestScore = -1000;
    int moveRow = -1, moveCol = -1;

    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (board[i][j] == ' '){
                board[i][j] = 'O'; // Try move
                int score = minimax(board, false);
                board[i][j] = ' ';

                if (score > bestScore){
                    bestScore = score;
                    moveRow = i;
                    moveCol = j;
                }
            }
        }
    }
    if (moveRow != -1 && moveCol != -1){
        board[moveRow][moveCol] = 'O';
        printf("Computer choice: %d %d\n", moveRow, moveCol);
    }
}

void computerPick(char board[3][3]) {
    if (difficulty == 1) {
        easyComputer(board);
    } else if (difficulty == 2) {
        mediumComputer(board);
    } else if (difficulty == 3) {
        hardComputer(board);
    }
}
