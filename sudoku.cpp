/*--------------------------------------------------------------------------+
|  IMPLEMENTATION FILE                                                      |
|  File Name:    sudoku.cpp                                                 |
|  Student:      Desy Kristianti                                            |
|  Coursework:   MSc C++ Programming - Assessed Exercise No. 1              |
|  Date:         29 October 2015                                            |
+--------------------------------------------------------------------------*/

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


/* add your functions here */

/*--------------------------+
|  START OF STUDENT'S WORK  |
+--------------------------*/

/*--------------------------------------------------------------------------+
|  TASK 1                                                                   |
|  Function to check if all entries in a given Sudoku board is a digit      |
+--------------------------------------------------------------------------*/

bool is_complete(char board[9][9]) {

  for (int r=0; r<9; r++) {
    for (int c=0; c<9; c++) {

      if (!isdigit(board[r][c]))
	return 0;

    }
  }
  return 1;
}

/*--------------------------------------------------------------------------+
|  TASK 2                                                                   |
|  Function to check if placing a given digit onto a given Sudoku board     |
|  at a given position is a valid move, and make the move if valid.         |
+--------------------------------------------------------------------------*/

bool make_move(char position[3], char digit, char board[9][9]) {

  if (position[0] < 65 || (position[0] > 73 && position[0] < 97) || position[0] > 105)
    return 0;
  else if (position[1] < 49 || position[1] > 57)
    return 0;

  int position_row;
  if (position[0] >= 65 && position[0] <= 73) // Upper case letter input
    position_row = position[0] - 65;
  else if (position[0] >= 97 && position[0] <= 105) // Lower case letter input
    position_row = position[0] - 97;

  int position_col = position[1] - 49;

  if (!check(position_row, position_col, digit, board))
    return 0;

  board[position_row][position_col] = digit;
  return 1;
}

/*--------------------------------------------------------------------------+
|  TASK 3                                                                   |
|  Function to save a given Sudoku board in a file named "filename"         |
+--------------------------------------------------------------------------*/

bool save_board(const char *filename, char board[9][9]) {

  ofstream out_stream;
  out_stream.open(filename);

  if (out_stream.fail())
    return 0;

  for (int r=0; r<9; r++) {

    for (int c=0; c<9; c++) {
      out_stream.put(board[r][c]);
    }

    out_stream << endl;
  }

  out_stream.close();

  return 1;
}

/*--------------------------------------------------------------------------+
|  TASK 4                                                                   |
|  Function to solve a given Sudoku puzzle.                                 |
|  When a solution is found, the function returns 1 and                     |
|    updates the board with the solution.                                   |
|  When a solution does not exist, the function returns 0 and               |
|    the board remains unchanged.                                           |
+--------------------------------------------------------------------------*/

bool solve_board(char board[9][9]) {

  if (!is_valid(board))
    return 0;
  if (is_complete(board))
    return 1;

  char position[3];

  for (int r=0; r<9; r++) {
    for (int c=0; c<9; c++) {
      position[0] = r + 65;
      position[1] = c + 49;

      if (board[r][c] == '.') {

	for (char guess='1'; guess<='9'; guess++) {
	  
	    if (make_move(position, guess, board)) { // guess is a valid entry

	      if (solve_board(board)) // The updated board has a solution
		return 1;

	      else
		board[r][c] = '.';
	      
	    }
	    // guess is not a valid entry. Try the next guess.
	}

	// All possible guesses have been attempted for this cell
	// Reaching this point means this cell has no possible entry
	return 0;
      }

    }
  }

  return 0;
}

/*--------------------------------------------------------------------------+
|  TASK 5                                                                   |
|  Polymorphic function to solve a given Sudoku puzzle while keeping track  |
|  of the number of iterations taken to solve the puzzle                    |
+--------------------------------------------------------------------------*/

bool solve_board(char board[9][9], int &count) {

  count++;

  if (!is_valid(board))
    return 0;
  if (is_complete(board))
    return 1;

  char position[3];

  for (int r=0; r<9; r++) {
    for (int c=0; c<9; c++) {
      position[0] = r + 65;
      position[1] = c + 49;

      if (board[r][c] == '.') {
	
	for (char guess='1'; guess<='9'; guess++) {
	  
	    if (make_move(position, guess, board)) {

	      if (solve_board(board, count))
		return 1;
	      
	      else 
		board[r][c] = '.';
	      
	    }
	}

	return 0;
      }
    }
  }
  return 0;
}

/*-------------------+
|  HELPER FUNCTIONS  |
+-------------------*/

/* Function to confirm that a given digit is not repeated in the same row */
bool check_row(int row_number, char digit, char board[9][9]) {

  for (int c=0; c<9; c++) {
    if(board[row_number][c] == digit)
      return 0;
  }

  return 1;
}
/* End of function */

/* Function to confirm that a given digit is not repeated in the same column */
bool check_col(int col_number, char digit, char board[9][9]) {

  for (int r=0; r<9; r++) {
    if (board[r][col_number] == digit)
      return 0;
  }

  return 1;
}
/* End of function */

/* Function to confirm that a given digit is not repeated in the same sub-grid*/
bool check_subgrid(int row_number, int col_number, char digit, char board[9][9]) {

  int sub_grid_row_start = row_number - (row_number % 3);
  int sub_grid_col_start = col_number - (col_number % 3);

  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      if (board[sub_grid_row_start+i][sub_grid_col_start+j] == digit)
	return 0;
    }
  }

  return 1;
}
/* End of function */

/* Function to confirm that a given digit is not repeated in the same row, column, or sub-grid */
bool check(int row_number, int col_number, char digit, char board[9][9]) {

  if (!check_row(row_number, digit, board)) 
    return 0;
  else if (!check_col(col_number, digit, board))
    return 0;
  else if (!check_subgrid(row_number, col_number, digit, board))
    return 0;

  return 1;
}
/* End of function */

/* Function to check if a given Sudoku board is valid. */
bool is_valid(char board[9][9]) {

  for (int r=0; r<9; r++) {
    for (int c=0; c<9; c++) {

      if (isdigit(board[r][c])) {
	char temp_value = board[r][c];
	board[r][c] = '.';

	if (!check(r, c, temp_value, board))
	  return 0;

	board[r][c] = temp_value;
      }
    }
  }

  return 1;
}
/* End of function */

/*------------------------+
|  END OF STUDENT'S WORK  |
+------------------------*/
