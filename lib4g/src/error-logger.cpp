#include <iostream>
#include "colors.hpp"
#include "error-logger.hpp"

namespace lib4g {
	void logError(char const* errorMsg) {
		std::cout << lib4g::COLOR_RED << errorMsg << lib4g::COLOR_RESET << std::endl;
		exit(-1);
	}
}