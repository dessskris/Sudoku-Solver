CXX=g++ -Wall -g

sudoku: main.o sudoku.o
	$(CXX) main.o sudoku.o -o sudoku

%.o: %.cpp sudoku.h
	$(CXX) -c $<

.PHONY: clean
clean:
	rm -f sudoku *.o
