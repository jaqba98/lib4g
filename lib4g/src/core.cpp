#include <iostream>
#include "input-validation.hpp"
#include "core.hpp"

namespace lib4g {
	void Core::run(int width, int height, std::string title) {
		lib4g::validations::InputValidation* inputValidation = new lib4g::validations::InputValidation();
		inputValidation->validation(width, height, title);
		delete inputValidation;
	}
}