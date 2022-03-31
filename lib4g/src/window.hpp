#pragma once

namespace lib4g {
	namespace builders {
		class Window {
		public:
			void createWindow(int width, int height, std::string title);
			GLFWwindow* getWindow();
		private:
			GLFWwindow* window;
		};
	}
}