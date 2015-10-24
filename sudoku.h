#ifndef SUDOKU_H

void load_board(const char *filename, char board[9][9]);
void display_board(const char board[9][9]);
void print_frame(int row);
void print_row(const char *data, int row);
bool is_complete(char board[9][9]);
bool make_move(char position[3], char digit, char board[9][9]);
bool save_board(const char *filename, char board[9][9]);
bool solve_board(char board[9][9]);
bool check_row(int row_number, char digit, char board[9][9]);
bool check_col(int col_number, char digit, char board[9][9]);
bool check_subgrid(int row_number, int col_number, char digit, char board[9][9]);
bool is_valid(char board[9][9]);

#define SUDOKU_H
#endif
