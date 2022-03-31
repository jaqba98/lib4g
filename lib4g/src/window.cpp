#include <iostream>
#include <GLFW/glfw3.h>
#include "error-builder.hpp"
#include "window.hpp"

namespace lib4g {
	namespace builders {
		void Window::createWindow(int width, int height, std::string title) {
			window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
			if (window == NULL) {
				lib4g::builders::throwError("Failed to create window");
			}
			glfwMakeContextCurrent(window);
		}

		GLFWwindow* Window::getWindow() {
			return window;
		}
	}
}