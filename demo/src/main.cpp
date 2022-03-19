#include "lib4g.hpp"

int main() {
	lib4g::game* game = new lib4g::game(640, 480, "Game");
	delete game;
	return 0;
}