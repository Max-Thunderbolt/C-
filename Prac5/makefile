ofiles = main.o IsDivisible.o IsEvenOdd.o IsGreater.o IsPrimeNumber.o IsSmaller.o NumberTester.o TesterInterface.o ValueDependantTester.o ValueIndependantTester.o
gpp_o = g++ -c -std=c++98

main: $(ofiles)
	g++ -o main $(ofiles)

main.o: main.cpp
	$(gpp_o) main.cpp

IsDivisible.o: IsDivisible.cpp IsDivisible.h
	$(gpp_o) IsDivisible.cpp

IsEvenOdd.o: IsEvenOdd.cpp IsEvenOdd.h
	$(gpp_o) IsEvenOdd.cpp

IsGreater.o: IsGreater.cpp IsGreater.h
	$(gpp_o) IsGreater.cpp

IsPrimeNumber.o: IsPrimeNumber.cpp IsPrimeNumber.h
	$(gpp_o) IsPrimeNumber.cpp

IsSmaller.o: IsSmaller.cpp IsSmaller.h
	$(gpp_o) IsSmaller.cpp

NumberTester.o: NumberTester.cpp NumberTester.h
	$(gpp_o) NumberTester.cpp

TesterInterface.o: TesterInterface.cpp TesterInterface.h
	$(gpp_o) TesterInterface.cpp

ValueDependantTester.o: ValueDependantTester.cpp ValueDependantTester.h
	$(gpp_o) ValueDependantTester.cpp

ValueIndependantTester.o: ValueIndependantTester.cpp ValueIndependantTester.h
	$(gpp_o) ValueIndependantTester.cpp

run: main
	./main

clean:
	rm *.o main