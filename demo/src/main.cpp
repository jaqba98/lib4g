#include "lib4g.hpp"

int main() {
	Lib4g* game = new Lib4g();
	game->run(640, 480, "Demo");
	delete game;
	return 0;
}