#include <iostream>
#include "error-builder.hpp"
#include "core.hpp"
#include "lib4g.hpp"

namespace lib4g {
	void Lib4g::run(int width, int height, std::string title) {
		try {
			lib4g::Core* core = new lib4g::Core();
			core->run(width, height, title);
			delete core;
		}
		catch (char const* error) {
			lib4g::builders::throwError(error);
		}
		catch (...) {
			lib4g::builders::throwError("Unexpected error!");
		}
	}
}