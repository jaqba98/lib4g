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
		//throw std::runtime_error("error validation");
	}
}