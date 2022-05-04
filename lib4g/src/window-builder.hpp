#pragma once

#include <iostream>
#include <GLFW/glfw3.h>

namespace lib4g {
	namespace builder {
		class WindowBuilder {
		public:
			GLFWwindow* window;
			void init();
			void create(int width, int height, std::string title);
		};
	}
}
