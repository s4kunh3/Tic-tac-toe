#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <stdbool.h>

extern int difficulty;

void initBoard(char board[3][3]);
void printBoard(char board[3][3]);
bool checkWin(char board[3][3], char player);
bool isBoardFull(char board[3][3]);
void setDifficulty();
void playerPick(char board[3][3]);

#endif
