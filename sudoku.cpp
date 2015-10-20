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
   at a given position */
Bool make_move(char position[3], char digit, char board[9][9]) {
  if (!(position[0]>64 && position[0]<91)) { //The first character is an uppercase letter
    return 0;
  }

  if (!(position[0]>96 && position[0]<123)) { //The first character is a lower case letter
    return 0;
  }

}

/* add your functions here */
