#include "core.hpp"

namespace lib4g {
	namespace core {
		void Core::run(int width, int height, std::string title) {
			lib4g::validator::WindowValidator* windowValidator = new lib4g::validator::WindowValidator();
			lib4g::builder::WindowBuilder* windowBuilder = new lib4g::builder::WindowBuilder();
			windowValidator->inputData(width, height, title);
			windowBuilder->init();
			windowBuilder->create(width, height, title);
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
				throw "Failed to initalize glad";
			}
			glfwSetFramebufferSizeCallback(windowBuilder->window, lib4g::core::framebufferSizeCallback);

			GLint success;
			GLchar infoLog[512];
			
			const GLchar* vertexShaderSource = "#version 330 core\n"
				"layout (location = 0) in vec3 aPos;\n"
				"void main() {\n"
				"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
				"}\0";
			GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
			glCompileShader(vertexShader);
			glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
			if (!success) {
				glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
				std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
			}

			const GLchar* fragmentShaderSource = "#version 330 core\n"
				"out vec4 FragColor;\n"
				"void main() {\n"
				"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
				"}\0";
			GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
			glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
			glCompileShader(fragmentShader);
			glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
			if (!success) {
				glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
				std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
			}

			GLuint shaderProgram = glCreateProgram();
			glAttachShader(shaderProgram, vertexShader);
			glAttachShader(shaderProgram, fragmentShader);
			glLinkProgram(shaderProgram);
			glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
			if (!success) {
				glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
				std::cout << "ERROR::SHADER::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
			}

			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			float vertices[] = {
				 0.5f,  0.5f, 0.0f,
				 0.5f, -0.5f, 0.0f,
				-0.5f,  0.5f, 0.0f,
				 0.5f, -0.5f, 0.0f,
				-0.5f, -0.5f, 0.0f,
				-0.5f,  0.5f, 0.0f
			};

			GLuint VAO, VBO;

			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);
			
			glBindVertexArray(VAO);
			
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);
			
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindVertexArray(0);

			while (!glfwWindowShouldClose(windowBuilder->window)) {
				processInput(windowBuilder->window);
				glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT);
				glUseProgram(shaderProgram);
				glBindVertexArray(VAO);
				glDrawArrays(GL_TRIANGLES, 0, 6);
				glfwSwapBuffers(windowBuilder->window);
				glfwPollEvents();
			}
			glfwTerminate();

			glDeleteVertexArrays(1, &VAO);
			glDeleteBuffers(1, &VBO);
			glDeleteProgram(shaderProgram);

			delete windowValidator, windowBuilder;
		}

		void Core::processInput(GLFWwindow* window) {
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
				glfwSetWindowShouldClose(window, GLFW_TRUE);
			}
		}

		void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);
		}
	}
}
