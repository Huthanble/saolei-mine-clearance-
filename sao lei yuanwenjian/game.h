#pragma once
#include<stdio.h>
#define ROW 9
#define ROWS ROW+2
#define COL 9
#define COLS COL+2
#define easycount 10
#include<stdlib.h>
#include<time.h>
void initboard(char board[ROWS][COLS], int rows, int cols,char set);
void displayboard(char board[ROWS][COLS], int row, int col);
void setmine(char board[ROWS][COLS], int row, int col);
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
