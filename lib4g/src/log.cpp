#include <iostream>
#include "colors.hpp"
#include "log.hpp"

namespace lib4g {
	namespace log {
		void error(char const* msg) {
			std::cout << lib4g::consts::RED << msg << lib4g::consts::RESET << std::endl;
		}
	}
}