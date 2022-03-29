#include <iostream>
#include "console-colors.hpp"
#include "error-builder.hpp"

namespace lib4g {
	namespace builders {
		std::string throwError(std::string error) {
			return lib4g::colors::CONSOLE_RED + "Error: " + error + lib4g::colors::CONSOLE_RESET;
		}
	}
}