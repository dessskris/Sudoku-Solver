/*--------------------------------------------------------------------------+
|  HEADER FILE                                                              |
|  File Name:    sudoku.h                                                   |
|  Student:      Desy Kristianti                                            |
|  Coursework:   MSc C++ Programming - Assessed Exercise No. 1              |
|  Date:         2 November 2015                                            |
+--------------------------------------------------------------------------*/

#ifndef SUDOKU_H
#define SUDOKU_H

/* PRE-SUPPLIED HELPER FUNCTIONS */
void load_board(const char *filename, char board[9][9]);
void display_board(const char board[9][9]);
void print_frame(int row);
void print_row(const char *data, int row);

/* FUNCTION TO CONFIRM IF ALL ENTRIES IN board IS A DIGIT */
bool is_complete(char board[9][9]);

/* FUNCTION TO CONFIRM THAT PLACING digit ONTO board AT CELL position IS A
   VALID MOVE, AND MAKE THE MOVE IF VALID */
bool make_move(char position[3], char digit, char board[9][9]);

/* FUNCTION TO SAVE board IN A FILE CALLED filename */
bool save_board(const char *filename, char board[9][9]);

/* FUNCTION TO SOLVE board
   WHEN A SOLUTION IS FOUND, IT RETURNS 1 AND UPDATES board WITH THE SOLUTION.
   OTHERWISE, IT RETURNS 0 AND board REMAINS UNCHANGED. */
bool solve_board(char board[9][9]);

/* POLYMORPHIC FUNCTION TO SOLVE board AND COUNT THE NUMBER OF ITERATIONS
   TAKEN TO SOLVE THE PUZZLE */
bool solve_board(char board[9][9], int &count);

/*-------------------+
|  HELPER FUNCTIONS  |
+-------------------*/

/* FUNCTION TO CONFIRM THAT digit DOES NOT ALREADY EXIST IN ROW row_number */
bool check_row(int row_number, char digit, char board[9][9]);

/* FUNCTION TO CONFIRM THAT digit DOES NOT ALREADY EXIST IN COLUMN col_number */
bool check_col(int col_number, char digit, char board[9][9]);

/* FUNCTION TO CONFIRM THAT digit DOES NOT ALREADY EXIST IN ITS SUBGRID */
bool check_subgrid(int row_number, int col_number, char digit, char board[9][9]);

/* FUNCTION TO CONFIRM THAT digit DOES NOT ALREADY EXIST IN
   ITS ROW, COLUMN, OR SUBGRID */
bool check(int row_number, int col_number, char digit, char board[9][9]);

/* FUNCTION TO CONFIRM THAT board IS A VALID BOARD WITH NO REPEATED DIGITS */
bool is_valid(char board[9][9]);

#endif
