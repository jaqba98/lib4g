#pragma once

namespace lib4g {
	class window_pc {
	public:
		window_pc(int width, int height, const char* title);
	private:
		int width;
		int height;
		const char* title;
	};
}