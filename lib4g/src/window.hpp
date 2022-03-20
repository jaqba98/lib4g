#pragma once

namespace lib4g {
	class window {
	public:
		window(int width, int height, const char* title);
	private:
		unsigned int width;
		unsigned int height;
		const char* title;
		void validation();
	};
}