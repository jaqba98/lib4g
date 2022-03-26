#include <iostream>
#include "colors.hpp"
#include "error-logger.hpp"

namespace lib4g {
	void logError(char const* message) {
		std::cout << lib4g::COLOR_RED << "Error: " << message << lib4g::COLOR_RESET << std::endl;
		exit(-1);
	}
}