#include "lib4g.hpp"
#include "log.hpp"

namespace lib4g {
	void Lib4g::run(int width, int height, const char* title) {
		try {
			throw "Excepted error!";
		}
		catch (char const* error) {
			lib4g::log::error(error);
		}
		catch (...) {
			lib4g::log::error("Unexcepted error!");
		}
	}
}