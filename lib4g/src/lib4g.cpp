#include "lib4g.hpp"
#include "logger.hpp"

namespace lib4g {
	void Lib4g::run(int width, int height, const char* title) {
		try {
			throw ":(";
		}
		catch (char const* error) {
			lib4g::logger::error(error);
		}
		catch (...) {
			lib4g::logger::error("-_-");
		}
	}
}