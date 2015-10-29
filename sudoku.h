/*--------------------------------------------------------------------------+
|  HEADER FILE                                                              |
|  File Name:    sudoku.h                                                   |
|  Student:      Desy Kristianti                                            |
|  Coursework:   MSc C++ Programming - Assessed Exercise No. 1              |
|  Date:         29 October 2015                                            |
+--------------------------------------------------------------------------*/

#ifndef SUDOKU_H
#define SUDOKU_H

/* PRE-SUPPLIED HELPER FUNCTIONS */
void load_board(const char *filename, char board[9][9]);
void display_board(const char board[9][9]);
void print_frame(int row);
void print_row(const char *data, int row);

/* FUNCTION TO CHECK IF ALL ENTRIES IN board IS A DIGIT */
bool is_complete(char board[9][9]);

/* FUNCTION TO PLACE digit ONTO board AT CELL position */
bool make_move(char position[3], char digit, char board[9][9]);

/* FUNCTION TO SAVE board IN THE FILE filename */
bool save_board(const char *filename, char board[9][9]);

/* FUNCTION TO SOLVE board */
bool solve_board(char board[9][9]);

/* FUNCTION TO SOLVE board AND COUNT THE NUMBER OF ITERATIONS */
bool solve_board(char board[9][9], int &count);

/* HELPER FUNCTION TO CONFIRM THAT digit IS NOT REPEATED IN ROW row_number */
bool check_row(int row_number, char digit, char board[9][9]);

/* HELPER FUNCTION TO CONFIRM THAT digit IS NOT REPEATED IN COLUMN col_number */
bool check_col(int col_number, char digit, char board[9][9]);

/* HELPER FUNCTION TO CONFIRM THAT digit IS NOT REPEATED IN ITS SUBGRID */
bool check_subgrid(int row_number, int col_number, char digit, char board[9][9]);

/* HELPER FUNCTION TO CONFIRM THAT digit IS NOT REPEATED IN ITS ROW, COLUMN, OR SUBGRID */
bool check(int row_number, int col_number, char digit, char board[9][9]);

/* HELPER FUNCTION TO CONFIRM THAT board IS A VALID BOARD */
bool is_valid(char board[9][9]);

#endif
