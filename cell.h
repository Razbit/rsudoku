#ifndef CELL_H
#define CELL_H

#define N_1 0x001
#define N_2 0x002
#define N_3 0x004
#define N_4 0x008
#define N_5 0x010
#define N_6 0x020
#define N_7 0x040
#define N_8 0x080
#define N_9 0x100
#define N_ALL 0x1FF

class Cell
{
public:
	/* Creates an empty cell */
	Cell();
	/* Creates a cell with number n */
	Cell(int _n);
	~Cell(){};

	void set(int _n);
	int get();

	void add_note(unsigned int n);
	void set_notes(unsigned int n);
	void rm_note(unsigned int n);
	unsigned int get_notes();
	int n_notes();

private:
	int n;
	unsigned int notes;
	
};

#endif /* CELL_H *//* notes */
