#include "lib4g.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace lib4g {
	window_pc::window_pc(int width, int height, const char* title) {
		this->width = width;
		this->height = height;
		this->title = title;
		
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif
		GLFWwindow* window = glfwCreateWindow(this->width, this->height, this->title, NULL, NULL);
		while (!glfwWindowShouldClose(window)) {
			glfwPollEvents();
		}
		glfwTerminate();
	}
}