#include "lib4g.hpp"
#include "lib4g-core.hpp"
#include "lib4g-errors.hpp"

void Lib4g::run(int width, int height, const char* title) {
	try {
		Lib4gCore* core = new Lib4gCore(width, height, title);
		core->run();
		delete core;
	}
	catch (char const* err) {
		error(err);
	}
	catch (...) {
		error("Not defined error!");
	}
}