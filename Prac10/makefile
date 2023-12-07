ofiles = main.o Disk.o TowersOfHanoi.o IterativeSolution.o RecursiveSolution.o
gpp_o = g++ -c -std=c++98 -static

main: $(ofiles)
	g++ -o main  $(ofiles)

main.o: main.cpp Disk.cpp TowersOfHanoi.cpp IterativeSolution.cpp RecursiveSolution.cpp
	$(gpp_o) main.cpp

Disk.o: Disk.cpp Disk.h
	$(gpp_o) Disk.cpp

TowersOfHanoi.o: TowersOfHanoi.cpp TowersOfHanoi.h
	$(gpp_o) TowersOfHanoi.cpp

IterativeSolution.o: IterativeSolution.cpp IterativeSolution.h
	$(gpp_o) IterativeSolution.cpp

RecursiveSolution.o: RecursiveSolution.cpp RecursiveSolution.h
	$(gpp_o) RecursiveSolution.cpp

run: main
	./main

clean: 
	rm *.o main