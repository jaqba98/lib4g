#include "window.hpp"
#include <iostream>

namespace lib4g {
	window::window(int width, int height, const char* title) {
		this->width = width;
		this->height = height;
		this->title = title;
		validation();
	}

	void window::validation() {
		try {
			if (width < 0) {
				throw "window width cannot be less than 0";
			}
			if (height < 0) {
				throw "window height cannot be less than 0";
			}
			if (title == "") {
				throw "window title cannot be empty";
			}
		}
		catch (char const* err) {
			std::cout << "Failed to initialize window data: " << err << std::endl;
		}
	}
}