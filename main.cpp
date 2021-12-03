#include <iostream>
#include "Exceptions.h"
using namespace std;

double safeDivide(int top, int bottom) throw (DivideByZero);

int main() {

	int i = 0;
	double result = 0.0;

	try {
		cout << "Enter an integer: ";
		cin >> i;
		if (cin.fail()) throw NotInt("Not an integer.");
		cout << "You entered: " << i << endl;
		result = safeDivide(17, i);
		cout << "17 / " << i << " = " << result << endl;
	}
	catch (NotInt e) {
		cout << e.whatHappened() << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	catch (OutOfRange e) {
		if (e.isSpecified()) cout << e.getValue() << " is ";
		cout << "not permitted." << endl;
	}
	catch (DivideByZero e) {
		cout << "Divide by zero error." << endl;
	}

	return 0;
}

double safeDivide(int top, int bottom) throw(DivideByZero) {

	if (bottom == 0)
		throw DivideByZero();
	return top/static_cast<double>(bottom);
}