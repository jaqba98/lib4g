#include "lib4g-errors.hpp"
#include "lib4g-colors.hpp"
#include <iostream>

void error(char const* err) {
	std::cout << RED << "Error: " << err << RESET << std::endl;
}