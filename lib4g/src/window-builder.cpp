#include "window-builder.hpp"

namespace lib4g {
	namespace builder {
		void WindowBuilder::init() {
			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif
		}

		void WindowBuilder::create(int width, int height, std::string title) {
			window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
			if (window == NULL) {
				throw "Failed to create window";
			}
			glfwMakeContextCurrent(window);
		}
	}
}
