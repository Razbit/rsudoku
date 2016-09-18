#include "sudoku.h"
#include "cell.h"

#include <cstdio>

Cell* Sudoku::at(int x, int y)
{
	return grid[9*y+x];
}

Cell* Sudoku::at_33(int gx, int gy, int x, int y)
{
	int _x = 3*gx + x;
	int _y = 3*gy + y;
	return at(_x, _y);
}

Sudoku::Sudoku(const char* filename)
{
	int n;
	FILE* fp;
	char buf[16];
	
	fp = fopen(filename, "r");
	
	for(int i = 0; i < 9 && fgets(buf, 16, fp); i++)
	{
		for (int j = 0; j < 9; j++)
		{			
			n = buf[j] - '0';
			if (n == 0)
			{
				grid[9*i + j] = new Cell();
			}
			else
			{
				grid[9*i + j] = new Cell(n);
			}
		}
	}
}

Sudoku::~Sudoku()
{
	for (int i = 0; i < 81; i++)
		delete grid[i];
}

void Sudoku::print()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int n = at(j, i)->get();
			if (n == 0)
				printf(" ");
			else
				printf("%d", n);
			if (j == 2 || j == 5)
				printf("|");
		}
		printf("\n");
		if (i == 2 || i == 5)
			printf("-----------\n");
	}
}

void Sudoku::print_notes()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%3.3x ", at(j,i)->get_notes());
			if (j==2 || j==5)
				printf("| ");
		}
		printf("\n");
		if (i==2 || i==5)
			printf("\n");
	}
}

void Sudoku::note_exclusion()
{
	/* remove impossible notes */
	/* Begin with rows */
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (at(j, i)->get() == 0)
			{
				for (int k = 0; k < 9; k++)
				{
					if (j == k)
						continue;

					at(j, i)->rm_note(at(k, i)->get());
				}
			}
		}
	}

	/* Then cols */
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (at(i, j)->get() == 0)
			{
				for (int k = 0; k < 9; k++)
				{
					if (j == k)
						continue;

					at(i, j)->rm_note(at(i, k)->get());
				}
			}
		}
	}

	/* Then the 3x3 grids */
	for (int gx = 0; gx < 3; gx++)
	{
		for (int gy = 0; gy < 3; gy++)
		{
			for (int x = 0; x < 3; x++)
			{
				for (int y = 0; y < 3; y++)
				{
					if (at_33(gx, gy, x, y)->get() == 0)
					{
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								at_33(gx, gy, x, y)->rm_note(at_33(gx, gy, j, i)->get());
							}
						}
					}
				}
			}
		}
	}
	
}

int Sudoku::filled()
{
	int n = 0;
	for (int i = 0; i < 81; i++)
		if (grid[i]->get() != 0)
			n++;
	return n;
}

/* If a cell has just one note, fill it */
int Sudoku::fill_singles()
{
	int fills = 0;

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (at(x, y)->n_notes() == 1)
			{
				fills++;
				unsigned int note = at(x, y)->get_notes();

				switch (note)
				{
				case N_1:
					at(x, y)->set(1);
					break;
				case N_2:
					at(x, y)->set(2);
					break;
				case N_3:
					at(x, y)->set(3);
					break;
				case N_4:
					at(x, y)->set(4);
					break;
				case N_5:
					at(x, y)->set(5);
					break;
				case N_6:
					at(x, y)->set(6);
					break;
				case N_7:
					at(x, y)->set(7);
					break;
				case N_8:
					at(x, y)->set(8);
					break;
				case N_9:
					at(x, y)->set(9);
					break;
				default:
					break;
				}
			}
		}
	}
	
	return fills;
}

void Sudoku::solve()
{
	int n = 0;
	do
	{
		note_exclusion();
		n = fill_singles();
		printf("Filled %d cells\n", n);
	} while (n != 0);
	
	print();
	if (filled() == 81)
		printf("Done.\n");
	else
		print_notes();
}
