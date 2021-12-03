#pragma once
#include <string>
class NotInt {
public:
	NotInt(std::string info = "??");
	std::string whatHappened();
private:
	std::string description;
};

class OutOfRange {
public:
	OutOfRange();
	OutOfRange(int val);
	int getValue();
	bool isSpecified();

private:
	int offendingValue;
	bool noValueSpecified;
};

class DivideByZero {};