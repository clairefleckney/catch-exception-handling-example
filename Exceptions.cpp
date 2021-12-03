#include "Exceptions.h"
NotInt::NotInt(std::string info) {
	description = info;
}
std::string NotInt::whatHappened() {
	return description;
}
OutOfRange::OutOfRange() : noValueSpecified(true) {}
OutOfRange::OutOfRange(int val) {
	offendingValue = val;
	noValueSpecified = false;
}
int OutOfRange::getValue() {
	return offendingValue;
}
bool OutOfRange::isSpecified() {
	return !noValueSpecified;
}