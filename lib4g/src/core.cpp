#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "input-validation.hpp"
#include "error-builder.hpp"
#include "window.hpp"
#include "core.hpp"

namespace lib4g {
	void Core::run(int width, int height, std::string title) {
		lib4g::validations::InputValidation* inputValidation = new lib4g::validations::InputValidation();
		lib4g::builders::Window* window = new lib4g::builders::Window();
		inputValidation->validation(width, height, title);
		initCore();
		window->createWindow(width, height, title);
		initOpenGL();
		glViewport(0, 0, width, height);
		while (!glfwWindowShouldClose(window->getWindow())) {
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(window->getWindow());
			glfwPollEvents();
		}
		deleteCore();
		delete inputValidation, window;
	}

	void Core::initCore() {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif
	}

	void Core::initOpenGL() {
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			lib4g::builders::throwError("Failed to initalize glad");
		}
	}

	void Core::deleteCore() {
		glfwTerminate();
	}
}