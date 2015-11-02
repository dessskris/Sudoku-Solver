/*--------------------------------------------------------------------------+
|  HEADER FILE                                                              |
|  File Name:    sudoku.h                                                   |
|  Student:      Desy Kristianti                                            |
|  Coursework:   MSc C++ Programming - Assessed Exercise No. 1              |
|  Date:         2 November 2015                                            |
+--------------------------------------------------------------------------*/

#ifndef SUDOKU_H
#define SUDOKU_H

/* Pre-supplied helper functions */
void load_board(const char *filename, char board[9][9]);
void display_board(const char board[9][9]);
void print_frame(int row);
void print_row(const char *data, int row);

/* Function to confirm if all entries in BOARD is a digit */
bool is_complete(char board[9][9]);

/* Function to confirm that placing DIGIT onto BOARD at cell POSITION is a
   valid move, and make the move if valid */
bool make_move(char position[3], char digit, char board[9][9]);

/* Function to save BOARD in a file called FILENAME */
bool save_board(const char *filename, char board[9][9]);

/* Function to solve BOARD
   When a solution is found, it returns 1 and updates BOARD with the solution.
   Otherwise, it returns 0 and BOARD remains unchanged. */
bool solve_board(char board[9][9]);

/* Polymorphic function to solve BOARD and count the number of iterations
   taken to solve the puzzle */
bool solve_board(char board[9][9], int &count);

/*-------------------+
|  HELPER FUNCTIONS  |
+-------------------*/

/* Function to confirm that DIGIT does not already exist in row ROW_NUMBER */
bool check_row(int row_number, char digit, char board[9][9]);

/* Function to confirm that DIGIT does not already exist in column COL_NUMBER */
bool check_col(int col_number, char digit, char board[9][9]);

/* Function to confirm that DIGIT does not already exist in its subgrid */
bool check_subgrid(int row_number, int col_number, char digit, char board[9][9]);

/* Function to confirm that DIGIT does not already exist in
   its row, column, or subgrid */
bool check(int row_number, int col_number, char digit, char board[9][9]);

/* Function to confirm that BOARD is a valid board with no repeated digits */
bool is_valid(char board[9][9]);

#endif
