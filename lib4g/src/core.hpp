#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "window-validator.hpp"
#include "window-builder.hpp"

namespace lib4g {
	namespace core {
		class Core {
		public:
			void run(int width, int height, std::string title);
		private:
			void processInput(GLFWwindow* window);
		};
		void framebufferSizeCallback(GLFWwindow* window, int width, int height);
	}
}
