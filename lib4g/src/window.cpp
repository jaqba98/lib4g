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
		}
		catch (char const* err) {
			std::cerr << "Failed to initialize window data: " << err << std::endl;
		}
	}
}