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
				throw 99;
			}
		}
		catch (int err) {
			std::cout << "Failed to initialize window data: " << err << std::endl;
		}
	}
}