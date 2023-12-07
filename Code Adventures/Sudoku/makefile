ofiles = main.o createGame.o printSudoku.o 
gpp_o = g++ -c -std=c++11 -static

main: $(ofiles)
	g++ -o main  $(ofiles)

main.o: main.cpp createGame.cpp printSudoku.cpp
	$(gpp_o) main.cpp

createGame.o: createGame.cpp createGame.h
	$(gpp_o) createGame.cpp

printSudoku.o: printSudoku.cpp printSudoku.h
	$(gpp_o) printSudoku.cpp

run: main
	./main

clean:
	rm *.o main

# Path: Code Adventures/Sudoku/main.cpp