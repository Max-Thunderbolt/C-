ofiles = Object.o ObjectList.o Player.o Wall.o Floor.o Game.o Map.o mainP1.o 
gpp_o = g++ -c -std=c++98 -static

main: $(ofiles)
	g++ -o main $(ofiles)


Object.o: Object.cpp Object.h
	$(gpp_o) Object.cpp

ObjectList.o: ObjectList.cpp ObjectList.h
	$(gpp_o) ObjectList.cpp

Player.o: Player.cpp Player.h
	$(gpp_o) Player.cpp

Wall.o: Wall.cpp Wall.h
	$(gpp_o) Wall.cpp

Floor.o: Floor.cpp Floor.h
	$(gpp_o) Floor.cpp

Game.o: Game.cpp Game.h
	$(gpp_o) Game.cpp

Map.o: Map.cpp Map.h
	$(gpp_o) Map.cpp

run: main
	./main

clean:
	rm *.o main


