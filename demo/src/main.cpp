#include "lib4g.hpp"
#include <iostream>

int main() {
	lib4g::game* game = new lib4g::game(640, 480, "Demo");
	delete game;
	return 0;
}