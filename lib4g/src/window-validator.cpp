#include "window-validator.hpp"

namespace lib4g {
	namespace validator {
		void WindowValidator::inputData(int width,	int height,	std::string title) {
			if (width <= 0) {
				throw "the window width must not be less or equal than 0";
			}
			if (height <= 0) {
				throw "the window height must not be less or equal than 0";
			}
			if (title.empty()) {
				throw "the window title must not be empty";
			}
		}
	}
}
