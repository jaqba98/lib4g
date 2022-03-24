#include "lib4g.hpp"

int main() {
	lib4g* game = new lib4g(640, 480, "Demo");
	delete game;
	return 0;
}