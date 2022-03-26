#include <iostream>
#include "colors.hpp"
#include "logger.hpp"

namespace lib4g {
	namespace logger {
		void error(char const* msg) {
			std::cout << lib4g::consts::RED << msg << lib4g::consts::RESET << std::endl;
		}
	}
}