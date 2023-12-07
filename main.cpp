#include <iostream>
#include "Exceptions.h"
using namespace std;

// This function is declared to throw an exception, basically making it one big 'try' block
double safeDivide(int top, int bottom) throw (DivideByZero);

int main() {

	int i = 0;
	double result = 0.0;
	char testAgain = 'y';

	while (testAgain == 'y') {
		try {
			cout << "Enter an integer between -100 and 100: ";
			cin >> i;
			if (cin.fail()) throw NotInt("Not an integer."); // if the user enters a value that is not an int

			if (i > 100) throw OutOfRange(i); // if the user enters a value above the desired range, pass the value

			if (i < -100) throw OutOfRange(); // if the user enters a value below the desired range, throw a general out of range error
			cout << "You entered: " << i << endl;
			result = safeDivide(17, i);
			cout << "17 / " << i << " = " << result << endl;
		}
		catch (NotInt e) { // whatHappened() returns the string that is put in the throw
			cout << e.whatHappened() << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		catch (OutOfRange e) { // OutOfRange returns the value it was passed, saying not permitted
			if (e.isSpecified()) cout << e.getValue() << " is not permitted." << endl;

			if (!e.isSpecified()) cout << "Please only enter values between -100 and 100." << endl;
		}
		catch (DivideByZero e) {
			cout << "Divide by zero error." << endl;
		}
		cout << "Would you like to test again?(y/n): ";
		cin >> testAgain;
	}

	return 0;
}

double safeDivide(int top, int bottom) throw(DivideByZero) {

	if (bottom == 0)
		throw DivideByZero(); // throws the error to be caught higher up in main()
	return top/static_cast<double>(bottom); // or returns the value (static cast the int to a double to divide properly)
}