#include <iostream>
#include <cstdio>
#include <ctime>
#include "sudoku.h"

using namespace std;

int main() {

  char board[9][9];

  /* This section illustrates the use of the pre-supplied helper functions. */
  cout << "============== Pre-supplied functions ==================" << endl << endl;

  cout << "Calling load_board():" << endl;
  load_board("easy.dat", board);

  cout << endl << "Displaying Sudoku board with display_board():" << endl;
  display_board(board);
  cout << "Done!" << endl << endl;

  cout << "====================== Question 1 ======================" << endl << endl;

  load_board("easy.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << endl << endl;

  load_board("easy-solution.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << endl << endl;

  cout << "====================== Question 2 ======================" << endl << endl;

  load_board("easy.dat", board);

  // Should be OK
  cout << "Putting '1' into I8 is ";
  if (!make_move("I8", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);

	// write more tests

  cout << "====================== Question 3 ======================" << endl << endl;

  load_board("easy.dat", board);
  if (save_board("easy-copy.dat", board))
    cout << "Save board to 'easy-copy.dat' successful." << endl;
  else
    cout << "Save board failed." << endl;
  cout << endl;

  cout << "====================== Question 4 ======================" << endl << endl;

  int count_e=0, count_m=0;
  clock_t te, tm;

  load_board("easy.dat", board);
  te = clock();
  if (solve_board(board, count_e)) {
    te = clock() - te;
    cout << "The 'easy' board has a solution:" << endl;
    display_board(board);
    cout << "The program took " << count_e << " iterations and " << te << " clicks."  << endl;
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;

  load_board("medium.dat", board);
  tm = clock();
  if (solve_board(board, count_m)) {
    tm = clock() - tm;
    cout << "The 'medium' board has a solution:" << endl;
    display_board(board);
    cout << "The program took " << count_m << " iterations and " << tm << " clicks." << endl;
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;

  load_board("impossible.dat", board);
  if (solve_board(board)) {
    cout << "The 'impossible' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;

	// write more tests

  cout << "====================== Question 5 ======================" << endl << endl;
 
  int count_1=0, count_2=0, count_3=0;
  clock_t t1, t3;

  load_board("mystery1.dat", board);
  t1 = clock();
  if (solve_board(board, count_1)) {
    t1 = clock() - t1;
    cout << "The 'mystery1' board has a solution:" << endl;
    display_board(board);
    cout << "The program took " << count_1 << " iterations and " << t1 << " clicks." << endl;
    save_board("mystery1-solution.dat", board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;

  load_board("mystery2.dat", board);
  if (solve_board(board, count_2)) {
    cout << "The 'mystery2' board has a solution:" << endl;
    display_board(board);
    cout << "The program took " << count_2 << " iterations." << endl;
    save_board("mystery2-solution.dat", board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;

  load_board("mystery3.dat", board);
  t3 = clock();
  if (solve_board(board, count_3)) {
    t3 = clock() - t3;
    cout << "The 'mystery3' board has a solution:" << endl;
    display_board(board);
    cout << "The program took " << count_3 << " iterations and " << t3 << " clicks." << endl;
    save_board("mystery3-solution.dat", board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;

	// write more tests

  return 0;
}
