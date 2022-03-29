#include <iostream>
#include "input-validation.hpp"

namespace lib4g {
	namespace validations {
		void InputValidation::validation(int width, int height, std::string title) {
			if (width < 0) {
				throw "the window width mustn't be less than 0!";
			}
			if (height <= 0) {
				throw "the window height cannot be less than 0!";
			}
			if (title == "") {
				throw "the window title cannot be empty!";
			}
		}
	}
}