#include "lib4g.hpp"
#include "error-logger.hpp"

namespace lib4g {
	void Lib4g::run(int width, int height, const char* title) {
		try {
			throw "Excepted error!";
		}
		catch (char const* error) {
			lib4g::logError(error);
		}
		catch (...) {
			lib4g::logError("Unexcepted error!");
		}
	}
}