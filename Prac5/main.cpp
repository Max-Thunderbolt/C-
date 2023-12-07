#include <iostream>
#include "NumberTester.h"
#include "TesterInterface.h"
#include "ValueDependantTester.h"
#include "ValueIndependantTester.h"
#include "IsDivisible.h"
#include "IsGreater.h"
#include "IsSmaller.h"
#include "IsPrimeNumber.h"
#include "IsEvenOdd.h"
using namespace std;

int main()
{    
	cout << "------------------DERIVED CLASSES EVALUATE FUNCTIONS TESTING-------------------------" << endl;
	NumberTester* test1 = new IsDivisible(3);
	cout << "Testing IsDivisible evaluate function: " << test1->evaluate(6) << endl;
	NumberTester* test2 = new IsGreater(7);
	cout << "Testing IsGreater evaluate function: " << test2->evaluate(5) << endl;
	NumberTester* test3 = new IsSmaller(4);
	cout << "Testing IsSmaller evaluate function: " << test3->evaluate(19) << endl;
	NumberTester* test4 = new IsPrimeNumber();
	cout << "Testing IsPrimeNumber evaluate function: " << test4->evaluate(13) << endl;
	NumberTester* test5 = new IsEvenOdd();
	cout << "Testing IsEvenOdd evaluate function: " << test5->evaluate(71) << endl;
	
	cout << "------------------TESTERINTERFACE CLASS CONSTRUCTOR TESTING-------------------------" << endl;
	TesterInterface* a = new TesterInterface(6);
	NumberTester** testarray = new NumberTester*[6];
	cout << "added test1 at index: " << a->addTester(test1->clone()) << endl;
	cout << "added test2 at index: " << a->addTester(test2->clone()) << endl;
	cout << "added test3 at index: " << a->addTester(test3->clone()) << endl;
	cout << "added test4 at index: " << a->addTester(test4->clone()) << endl;
	cout << "Current Number of Testers: " << a->getCurrNumTesters() << endl;
	cout << "removed test 4: " << a->removeTester(3) << endl;
	cout << "removed test 2: " << a->removeTester(1) << endl;
	cout << "removed test 3: " << a->removeTester(10) << endl;
	cout << "removed test 4: " << a->removeTester(3) << endl;
	cout << "removed test5: " << a->removeTester(-8) << endl;
	cout << "Current Number of Testers: " << a->getCurrNumTesters() << endl;
	cout << "added test 4 again at index : " << a->addTester(test4->clone()) << endl;
	cout << "Current Number of Testers: " << a->getCurrNumTesters() << endl;
	cout << "added test1 at index: " << a->addTester(test1->clone()) << endl;
	cout << "added test2 at index: " << a->addTester(test2->clone()) << endl;
	cout << "added test3 at index: " << a->addTester(test5->clone()) << endl;
	cout << "added test4 at index: " << a->addTester(test4->clone()) << endl;
	cout << "Current Number of Testers: " << a->getCurrNumTesters() << endl;
	
	cout << "------------------TESTERINTERFACE CLASS COPY CONSTRUCTOR TESTING-------------------------" << endl;
	cout << "----------Copy Constructor with pointer parameter------------" << endl;
	TesterInterface b(a);
	cout << "added test1 at index: " << b.addTester(test1->clone()) << endl;
	cout << "removed test1: " << b.removeTester(3) << endl;
	cout << "removed test3: " << b.removeTester(5) << endl;
	cout << "added test5 at index: " << b.addTester(test1->clone()) << endl;
	cout << "Current Number of Testers: " << b.getCurrNumTesters() << endl;
	cout <<"-----------Copy Constructor with reference parameter---------" << endl;
	TesterInterface c(b);
	cout << "added test3 at index: " << c.addTester(test3->clone()) << endl;
	cout << "removed test4: " << c.removeTester(2) << endl;
	cout << "added test2 at index: " << c.addTester(test2->clone()) << endl;
	cout << "added test1 at index: " << c.addTester(test2->clone()) << endl;
	cout << "Current Number of Testers: " << c.getCurrNumTesters() << endl;
	
	cout << "------------------TESTERINTERFACE CLASS EVALUATE FUNCTION TESTING-------------------------" << endl;
	bool flag = a->evaluate(12);
	cout << "With the given input Value, the evaluate function returns: " << flag << endl;
	int *aArray = a->failedTests(12);
	cout << "Number of Failed Tests for aArray: " << a->numberOfFailedTests(12) << endl;
	for(int i=0; i < 2;i++){
		cout << "Array index " << i << " has the value " << aArray[i] << endl;
	}
	
	TesterInterface* d = new TesterInterface(5);
	NumberTester* maintester = new IsGreater(4);
	NumberTester* t = new IsSmaller(9);
	d->addTester(maintester->clone());
	d->addTester(maintester->clone());
	d->addTester(t->clone());
	d->addTester(maintester->clone());
	d->addTester(maintester->clone());
	d->addTester(maintester->clone());
	cout << "removed maintester: " << d->removeTester(5) << endl;
	
	bool boolean = d->evaluate(5);
	cout << "With the given input value, the evaluate function returns: " << boolean << endl;
	int* dArray = d->failedTests(7);
	cout << "Number of failed Tests for dArray: " << d->numberOfFailedTests(7) << endl;
	for(int i=0; i < 0; i++){
		cout << "Array index " << i << " has the value " << dArray[i] << endl;
	}
	
	cout << "------------------TESTERINTERFACE CLASS FAILEDTESTS FUNCTION TESTING-------------------------" << endl;
	cout <<"Current Number of Testers: " << a->getCurrNumTesters() << endl;
	int* arr = a->failedTests(6);
	int bb = a->numberOfFailedTests(6);
	cout <<"Number of failed Tests: " << bb << endl;
	for(int i=0; i < bb; i++){
		cout << "Array index " << i << " has the value " << arr[i] << endl;
	}
	cout << endl;
	cout <<"Current Number of Testers: " << d->getCurrNumTesters() << endl;
	
	int* arrayPtr = d->failedTests(5);
	int aa = d->numberOfFailedTests(5);
	cout <<"Number of failed Tests: " << aa << endl;
	for(int i=0; i < aa; i++){
		cout << "Array index " << i << " has the value " << arrayPtr[i] << endl;
	}
	 
	cout << "------------------TESTERINTERFACE CLASS OVERLOADED [] OPERATOR FUNCTION TESTING-------------------------"<< endl;
	cout << "------First Test-----" << endl;
	NumberTester* ptr = d->operator[](2);
	cout << ptr << endl;
	cout << "-----Second Test-----" << endl;
	NumberTester* p = d->operator[](18);
	cout << p << endl;
	
	delete test1;
	delete test2;
	delete test3;
	delete test4;
	delete test5;
	delete t;
	delete maintester;
	delete a;
	delete d;
	delete [] testarray;
	return 0;
}

/* Expected output

------------------DERIVED CLASSES EVALUATE FUNCTIONS TESTING-------------------------
Testing IsDivisible evaluate function: 1
Testing IsGreater evaluate function: 0
Testing IsSmaller evaluate function: 0
Testing IsPrimeNumber evaluate function: 1
Testing IsEvenOdd evaluate function: 0
------------------TESTERINTERFACE CLASS CONSTRUCTOR TESTING-------------------------
added test1 at index: 0
added test2 at index: 1
added test3 at index: 2
added test4 at index: 3
Current Number of Testers: 4
removed test 4: 1
removed test 2: 1
removed test 3: 0
removed test 4: 0
removed test5: 0
Current Number of Testers: 2
added test 4 again at index : 1
Current Number of Testers: 3
added test1 at index: 3
added test2 at index: 4
added test3 at index: 5
added test4 at index: -1
Current Number of Testers: 6
------------------TESTERINTERFACE CLASS COPY CONSTRUCTOR TESTING-------------------------
----------Copy Constructor with pointer parameter------------
added test1 at index: -1
removed test1: 1
removed test3: 1
added test5 at index: 3
Current Number of Testers: 5
-----------Copy Constructor with reference parameter---------
added test3 at index: 5
removed test4: 1
added test2 at index: 2
added test1 at index: -1
Current Number of Testers: 6
------------------TESTERINTERFACE CLASS EVALUATE FUNCTION TESTING-------------------------
With the given input Value, the evaluate function returns: 0
Number of Failed Tests for aArray: 2
Array index 0 has the value 1
Array index 1 has the value 2
removed maintester: 0
With the given input value, the evaluate function returns: 1
Number of failed Tests for dArray: 0
------------------TESTERINTERFACE CLASS FAILEDTESTS FUNCTION TESTING-------------------------
Current Number of Testers: 6
Number of failed Tests: 3
Array index 0 has the value 1
Array index 1 has the value 2
Array index 2 has the value 4

Current Number of Testers: 5
Number of failed Tests: 0
------------------TESTERINTERFACE CLASS OVERLOADED [] OPERATOR FUNCTION TESTING-------------------------
------First Test-----
0x1427e90
-----Second Test-----
0


 */
