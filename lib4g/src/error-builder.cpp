#include <iostream>
#include <GLFW/glfw3.h>
#include "console-colors.hpp"
#include "error-builder.hpp"

namespace lib4g {
	namespace builders {
		void throwError(std::string error) {
			const std::string message = lib4g::colors::CONSOLE_RED + "Error: " + error + "!" + lib4g::colors::CONSOLE_RESET;
			std::cout << message << std::endl;
			glfwTerminate();
			exit(-1);
		}
	}
}