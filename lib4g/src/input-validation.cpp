#include <iostream>
#include "input-validation.hpp"

namespace lib4g {
	namespace validations {
		void InputValidation::validation(int width, int height, std::string title) {
			if (width <= 0) {
				throw "the window width mustn't be less or equal than 0";
			}
			if (height <= 0) {
				throw "the height width mustn't be less or equal than 0";
			}
			if (title.empty()) {
				throw "the window title cannot be empty";
			}
		}
	}
}