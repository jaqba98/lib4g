#include "error-builder.hpp"

namespace lib4g {
	namespace builder {
		void throwError(std::string error) {
			std::cout << "\033[31mError: " + error + "!\033[0m" << std::endl;
			glfwTerminate();
			exit(-1);
		}
	}
}
