ofiles = main.o
gpp_o = g++ -c -std=c++98 -static

main: $(ofiles)
	g++ -std=c++98 -static $(ofiles) -o main

main.o: main.cpp
	$(gpp_o) main.cpp

run: main
	./main

clean:
	rm *.o main