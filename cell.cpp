#include "cell.h"
#include <cstdio>

Cell::Cell()
{
	n = 0;
	notes = N_ALL;
}

Cell::Cell(int _n)
{
	n = _n;
	notes = 0;
}

void Cell::set(int _n)
{
	notes = 0;
	n = _n;
}

int Cell::get()
{
	return n;
}

void Cell::add_note(unsigned int n)
{
	notes |= (0x1 << (n-1));
}

void Cell::rm_note(unsigned int n)
{
	notes &= ~(0x1 << (n-1));
}

void Cell::set_notes(unsigned int n)
{
	notes = n;
}

unsigned int Cell::get_notes()
{
	return notes;
}

int Cell::n_notes()
{
	return __builtin_popcount(notes);
}
