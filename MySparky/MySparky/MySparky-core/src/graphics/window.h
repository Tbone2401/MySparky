#pragma once
#include <memory>
#include <glew.h>
#include <glfw3.h>

struct GLFWwindow;

namespace mysparky::graphics
{
	constexpr unsigned int max_keys = 1024;
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
		inline int GetWidth() const { return m_Width; }
		inline int GetHeight() const { return m_Height; }
		bool IsKeyPressed(unsigned int keyCode) const;
		bool IsMouseBtnPressed(unsigned int button) const;
		inline double GetCursorPositionX() const { return m_MouseX; };
		inline double GetCursorPositionY() const { return m_MouseY; };
		void PrintWindowResolution() const;

	private:
		bool Init();
		friend static void Window_resize(GLFWwindow *window, int width, int height);
		friend static void Key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
		friend static void Mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
		friend static void Cursor_position_callback(GLFWwindow *window, double xpos, double ypos);

		bool m_Keys[max_keys];
		bool m_MouseButtons[max_buttons];
		double m_MouseX, m_MouseY;

		const char *m_Title;
		int m_Width, m_Height;
		bool m_Closed;
		std::unique_ptr<GLFWwindow, DestroyglfwWindow> m_Window;

	};
}


