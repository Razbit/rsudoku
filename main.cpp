#include "sudoku.h"

int main(int argc, char* argv[])
{
	Sudoku* game = new Sudoku(argv[1]);
	game->print();
	game->solve();
	delete game;
	return 0;
}
