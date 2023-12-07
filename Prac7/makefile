ofiles = Event.o Calendar.o main.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -o main $(ofiles)

Event.o: Event.h Event.cpp
	$(gpp_o) Event.cpp

Calendar.o: Calendar.h Calendar.cpp
	$(gpp_o) Calendar.cpp

main.o: main.cpp
	$(gpp_o) main.cpp

run: main
	./main

leaks: 
	leaks: 
	leaks -atExit -- ./main

clean:
	rm *.o main



