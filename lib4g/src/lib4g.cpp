#include "lib4g.hpp"
#include "error-logger.hpp"
#include "messages.hpp"

namespace lib4g {
	void Lib4g::run(int width, int height, const char* title) {
		try {
			throw lib4g::TEST_ERROR;
		}
		catch (char const* error) {
			lib4g::logError(error);
		}
		catch (...) {
			lib4g::logError(lib4g::UNEXPECTED_ERROR);
		}
	}
}