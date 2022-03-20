#include "lib4g.hpp"
#include "window.hpp"
#include <iostream>

namespace lib4g {
	game::game(int width, int height, const char* title) {
		lib4g::window* window = new lib4g::window(width, height, title);
		delete window;
	}
}