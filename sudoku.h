#ifndef SUDOKU_H
#define SUDOKU_H

#include "cell.h"

class Sudoku
{
public:
	Sudoku(const char* filename);
	~Sudoku();

	void print();
	void print_notes();

	void solve();
	int filled();

private:
	Cell* at(int x, int y);
	Cell* at_33(int gx, int gy, int x, int y);

	void note_exclusion();
	int fill_singles();
	
	Cell* grid[81];
};

#endif /* SUDOKU_H */
