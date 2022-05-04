#include "lib4g.hpp"

int main() {
	lib4g::Lib4g* lib4g = new lib4g::Lib4g();
	lib4g->run(640, 480, "Demo");
	delete lib4g;
	return 0;
}
