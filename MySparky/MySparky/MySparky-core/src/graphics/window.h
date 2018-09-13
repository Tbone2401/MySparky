#pragma once
#include <memory>
#include <glew.h>
#include <glfw3.h>

struct GLFWwindow;

namespace mysparky
{
	namespace graphics
	{
		constexpr unsigned int max_height = 1024;
		constexpr unsigned int max_buttons = 32;

		struct DestroyglfwWindow 
		{
			void operator()(GLFWwindow* ptr) 
			{
				glfwDestroyWindow(ptr);
			}

		};

		class Window
		{
		public:

			Window(const char *name, int width, int height);
			~Window();
			void Update();
			bool Closed() const;
			void Clear() const;
			void Destroy() const;
			int GetWidth() const { return m_Width; }
			int GetHeight() const { return m_Height; }
			void PrintWindowResolution() const;

		private:
			bool Init();
			friend static void Window_resize(GLFWwindow *window, int width, int height);
			friend static void Key_callback(GLFWwindow * window, int key, int scancode, int action, int mods);

			static bool m_SKeys[max_height];
			static bool m_SMouseButtons[max_buttons];
			static double m_SMouseX, m_SMouseY;

			const char *m_Title;
			int m_Width, m_Height;
			bool m_Closed;
			std::unique_ptr<GLFWwindow, DestroyglfwWindow> m_Window;

		};
	}

}


