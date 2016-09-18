all:
	g++ -c -g sudoku.cpp -o sudoku.o
	g++ -c -g cell.cpp -o cell.o
	g++ -c -g main.cpp -o main.o
	g++ -g sudoku.o cell.o main.o -o rsudoku
