#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "input-validation.hpp"
#include "window.h"
#include "core.hpp"

namespace lib4g {
	void Core::run(int width, int height, std::string title) {
		lib4g::validations::InputValidation* inputValidation = new lib4g::validations::InputValidation();
		inputValidation->validation(width, height, title);
		initCore();
		lib4g::builders::Window* window = new lib4g::builders::Window();
		window->createWindow(width, height, title);
		deleteCore();
		delete inputValidation, window;
	}

	void Core::initCore() {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif
	}

	void Core::deleteCore() {
		glfwTerminate();
	}
}