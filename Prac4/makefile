ofiles = main.o TwoDArray.o SumArray.o CountArray.o SortArray.o 
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -o main $(ofiles)

main.o: main.cpp Task2.cpp
	$(gpp_o) main.cpp

Task2.o: Task2.cpp CountArray.h SumArray.h SortArray.h
	$(gpp_o) Task2.cpp

CountArray.o: CountArray.cpp TwoDArray.h
	$(gpp_o) CountArray.cpp

SumArray.o: SumArray.cpp TwoDArray.h
	$(gpp_o) SumArray.cpp

SortArray.o: SortArray.cpp TwoDArray.h
	$(gpp_o) SortArray.cpp

TwoDArray.o: TwoDArray.cpp TwoDArray.h
	$(gpp_o) TwoDArray.cpp

run: main
	./main

clean: 
	rm *.o main