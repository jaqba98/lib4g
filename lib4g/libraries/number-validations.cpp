#include "number-validations.hpp"

void Lib4gValidator::numberIsNotLess(int value, int minimum, char const* message) {
	if (value < minimum) {
		throw message;
	}
}