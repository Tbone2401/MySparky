#include "window.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

namespace mysparky
{
	namespace graphics
	{
		Window::Window(const char *title, int width, int height):
			m_Title(title), m_Width(width), m_Height(height)
		{
			if (!Init())
			{
				glfwTerminate();
			}
			for (int i = 0; i < max_buttons; i++)
			{
				//m_SKeys[i] = false;
			}
		}
		bool Window::Init()
		{
			if (!glfwInit())
			{
				cout << "Failed to initialise GLFW" << endl;
				return false;
			}

			//m_Window = std::make_unique<GLFWwindow, DestroyglfwWindow>(glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL));
			//make_unique does not support custom deleter
			m_Window = std::unique_ptr<GLFWwindow, DestroyglfwWindow>{glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL)};
			if (!m_Window)
			{
				cout << "Failed to create window!" << endl;
				return false;
			}
			glfwMakeContextCurrent(m_Window.get());
			glfwSetWindowUserPointer(m_Window.get(), this);
			glfwSetWindowSizeCallback(m_Window.get(), Window_resize);

			// Put this after the Context changing
			if (glewInit() != GLEW_OK)
			{
				cout << "Failed to initialise GLEW!" << endl;
				return false;
			}
			cout << glGetString(GL_VERSION) << endl;

			return true;
		}

		Window::~Window()
		{
			glfwTerminate();
		}
		void Window::Clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::Update()
		{
			glfwSwapBuffers(m_Window.get());
			glfwGetFramebufferSize(m_Window.get(), &m_Width, &m_Height);
			glfwPollEvents();
		}
		bool Window::Closed() const
		{
			return glfwWindowShouldClose(m_Window.get()) == 1;
		}
		void Window::Destroy() const
		{
			glfwDestroyWindow(m_Window.get());
		}
		void Window::PrintWindowResolution() const
		{
			cout << m_Width << ", " << m_Height << endl; 
		}
		void Window_resize(GLFWwindow *window, int width, int height)
		{
			Window* gameWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));
			gameWindow->m_Width = width;
			gameWindow->m_Height = height;
			glViewport(0, 0, width, height);
		}

		void Key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
		{
			Window* gameWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));
			//As long as key is not released it is pressed
			gameWindow->m_SKeys[key] = action != GLFW_RELEASE;
		}
	}
}