#include "core.hpp"
#include "error-builder.hpp"
#include "lib4g.hpp"

namespace lib4g {
	void Lib4g::run(int width, int height, std::string title) {
		try {
			lib4g::core::Core* core = new lib4g::core::Core();
			core->run(width, height, title);
			delete core;
		}
		catch (char const* error) {
			lib4g::builder::throwError(error);
		}
		catch (...) {
			lib4g::builder::throwError("Unexpected error!");
		}
	}
}
