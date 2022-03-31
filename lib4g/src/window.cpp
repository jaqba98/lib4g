#include <GLFW/glfw3.h>
#include <iostream>
#include "error-builder.hpp"
#include "window.hpp"

namespace lib4g {
	namespace builders {
		void Window::createWindow(int width, int height, std::string title) {
			this->window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
			if (this->window == NULL) {
				lib4g::builders::throwError("Failed to create window");
			}
			glfwMakeContextCurrent(this->window);
		}
	}
}