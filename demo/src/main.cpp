#include "lib4g.hpp"

int main() {
	lib4g::Lib4g* core = new lib4g::Lib4g();
	core->run(640, 480, "Demo");
	delete core;
	return 0;
}