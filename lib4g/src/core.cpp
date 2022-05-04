#include "core.hpp"

namespace lib4g {
	namespace core {
		void Core::run(int width, int height, std::string title) {
			lib4g::validator::WindowValidator* windowValidator = new lib4g::validator::WindowValidator();
			lib4g::builder::WindowBuilder* windowBuilder = new lib4g::builder::WindowBuilder();
			windowValidator->inputData(width, height, title);
			windowBuilder->init();
			windowBuilder->create(width, height, title);
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
				throw "Failed to initalize glad";
			}
			glfwSetFramebufferSizeCallback(windowBuilder->window, lib4g::core::framebufferSizeCallback);
			while (!glfwWindowShouldClose(windowBuilder->window)) {
				processInput(windowBuilder->window);
				render();
				glfwSwapBuffers(windowBuilder->window);
				glfwPollEvents();
			}
			glfwTerminate();
			delete windowValidator, windowBuilder;
		}

		void Core::processInput(GLFWwindow* window) {
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
				glfwSetWindowShouldClose(window, GLFW_TRUE);
			}
		}

		void Core::render() {
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
		}

		void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);
		}
	}
}
