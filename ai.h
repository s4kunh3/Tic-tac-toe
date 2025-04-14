#ifndef AI_H
#define AI_H
#include <stdbool.h>
extern int difficulty;

void easyComputer(char board[3][3]);
void mediumComputer(char board[3][3]);
void computerPick(char board[3][3]);
int minimax(char board[3][3], bool isMaximizing);
void hardComputer(char board[3][3]);

#endif
