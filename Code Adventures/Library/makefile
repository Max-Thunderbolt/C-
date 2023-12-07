ofiles = main.o book.o member.o 
gpp_o = g++ -c -std=c++11 -static

main: $(ofiles)
	g++ -o main  $(ofiles)

book.o: book.cpp book.h
	$(gpp_o) book.cpp

member.o: member.cpp member.h
	$(gpp_o) member.cpp
	
main.o: main.cpp book.cpp member.cpp
	$(gpp_o) main.cpp

run: main
	./main

clean:
	rm *.o main