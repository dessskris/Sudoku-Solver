#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <string>
#include "sudoku.h"

using namespace std;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char *filename, char board[9][9]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in)
    cout << "Failed!" << endl;
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  cout << ((row == 9) ? "Success!" : "Failed!") << endl;
  assert(row == 9);
}

/* internal helper function */
void print_frame(int row) {
  if (!(row % 3))
    cout << "  +===========+===========+===========+" << endl;
  else
    cout << "  +---+---+---+---+---+---+---+---+---+" << endl;
}

/* internal helper function */
void print_row(const char *data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|" << endl;
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++) 
    cout << (char) ('1'+r) << "   ";
  cout << endl;
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}


/* TASK 1 */
/* Function to check if all entries in a given Sudoku board is a digit */
Bool is_complete(char board[9][9]) {
  for (int r=0; r<9; r++) {
    for (int c=0; c<9; r++) {
      return isdigit(board[i][j]);
    }
  }
}


/* TASK 2 */
/* Function to place a given digit onto a given Sudoku board
   at a given position, if it is a valid move. */
Bool make_move(char position[3], char digit, char board[9][9]) {

  /* Confirm that the first character is a valid letter */
  if (position[0]<65 || (position[0]>73 && position[0]<97) || position[0]>105)
    return 0;

  /* Confirm that the second character is a valid number */
  if (position[1]<49 || position[1]>57)
    return 0;

  /* Define the row number ranging from 1 to 9 */
  int position_row;
  if (position[0]>=65 && position[0]<=73) // Upper case letter
    position_row = position[0] - 64;
  if (position[0]>=97 && position[0]<=105) // Lower case letter
    position_row = position[0] - 96;

  /* Define the column number ranging from 1 to 9 */
  int position_col = position[1] - 48;

  /* Confirm that the given digit is not repeated in the same row */
  for (int c=1, c<=9, c++) {
    if (board[position_row][c] == digit)
      return 0;
  }

  /* Confirm that the given digit is not repeated in the same column */
  for (int r=1, r<=9, r++) {
    if (board[r][position_col] == digit)
      return 0;
  }

  /* Confirm that the given digit is not repeated in the same sub-grid */
  /* First define the starting positions of the sub-grids */
  int sub_grid_row_start;
  if (position_row % 3 == 0) // position_row is 3, 6, or 9
    sub_grid_row_start = position_row - 2;
  else // position_row is 1, 2, 4, 5, 7, or 8
    sub_grid_row_start = position_row - (position_row % 3);

  int sub_grid_col_start;
  if (position_col % 3 == 0) // position_col is 3, 6, or 9
    sub_grid_col_start = position_col - 2;
  else // position_col is 1, 2, 4, 5, 7, or 8
    sub_grid_col_start = position_col - (position_col % 3);

  /* Now check the other entries in the sub-grid */
  for (int i=0, i<3, i++) {
    for (int j=0, j<3, j++) {
      if (board[sub_grid_row_start+i][sub_grid_col_start+j] == digit)
	return 0;
    }
  }

  /* At this stage, all checks have been performed.
     We proceed to make a valid move. */

  /* Place the given digit onto the given Sudoku board at the given position */
  board[position_row][position_col] = digit;
  return 1;
}


/* TASK 3 */
/* Function to save a given Sudoku board in a file named "filename" */
save_board(const char *filename, char board[9][9]) {
  ofstream out_stream;

  in_stream.


}

/* TASK 4 */
/* Function to solve a given Sudoku puzzle.
   When a solution is found, the function returns TRUE and
     updates the board with the solution.
   When a solution does not exist, the function returns FALSE and
     the board remains unchanged. */
Bool solve_board(char board[9][9]); {


}


/* HELPER FUNCTION */


/* add your functions here */
