main: *.o 
	g++ -o main *.o

*.o: *.cpp
	g++ -g -c *.cpp -std=c++98 -pedantic 

run: main 
	./main 

clean: 
	rm *.o main

