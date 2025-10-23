#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

#define COUNT 10

void Init(char Mine[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char Mine[ROWS][COLS], int row, int col);
void setmine(char Mine[ROWS][COLS], int row, int col);
void find_mine(char Mine[ROWS][COLS], char See[ROWS][COLS], int row, int col, int x, int y);
void extend(char Mine[ROWS][COLS], char See[ROWS][COLS], int row, int col, int x, int y);//周围无炸弹则拓宽格子
int Win(char See[ROWS][COLS], char Mine[ROWS][COLS]);
void sign(char See[ROWS][COLS], int row, int col);