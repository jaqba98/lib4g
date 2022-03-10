#include "lib4g.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace lib4g {
	window::window(int width, int height) {
		this->width = width;
		this->height = height;
	}
}