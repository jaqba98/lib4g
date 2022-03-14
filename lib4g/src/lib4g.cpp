#include "lib4g.hpp"

#include <iostream>
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
		if (window == NULL) {
			std::cout << "Failed to create window" << std::endl;
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(window);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Failed to initalize glad" << std::endl;
			return;
		}
		// glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
		glViewport(0, 0, this->width, this->height);
		while (!glfwWindowShouldClose(window)) {
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
				glfwSetWindowShouldClose(window, true);
			}
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		glfwTerminate();
	}
}