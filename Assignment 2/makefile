ofiles = matrix.o vector.o arithmetic.o  main.o 
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -o main $(ofiles)

arithmetic: arithmetic.cpp arithmetic.h
	$(gpp_o) arithmetic.cpp

matrix.o: matrix.h matrix.cpp
	$(gpp_o) matrix.cpp

vector.o: vector.h vector.cpp
	$(gpp_o) vector.cpp

main.o: main.cpp
	$(gpp_o) main.cpp

run: main
	./main

leaks:
	leaks -atExit -- ./main

clean:
	rm *.o main