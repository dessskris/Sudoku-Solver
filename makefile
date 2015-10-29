GXX=g++ -Wall -g

sudoku: main.o sudoku.o
	$(GXX) main.o sudoku.o -o sudoku

%.o: %.cpp sudoku.h
	$(GXX) -c $<

.PHONY: clean
clean:
	rm -f sudoku *.o
