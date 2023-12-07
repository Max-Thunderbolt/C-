ofiles = Cargo.o SecretCargo.o Passenger.o Plane.o Controller.o Exceptions.o main.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -o main $(ofiles)

Cargo.o: Cargo.cpp Cargo.h
	$(gpp_o) Cargo.cpp

SecretCargo.o: SecretCargo.cpp SecretCargo.h
	$(gpp_o) SecretCargo.cpp

Passenger.o: Passenger.cpp Passenger.h
	$(gpp_o) Passenger.cpp

Plane.o: Plane.cpp Plane.h	
	$(gpp_o) Plane.cpp

Controller.o: Controller.cpp Controller.h
	$(gpp_o) Controller.cpp

Exceptions.o: Exceptions.cpp Exceptions.h
	$(gpp_o) Exceptions.cpp

main.o: main.cpp
	$(gpp_o) main.cpp

run: main
	./main

clean:
	rm *.o main