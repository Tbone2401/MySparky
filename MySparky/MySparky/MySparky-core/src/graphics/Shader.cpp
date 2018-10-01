#include "Shader.h"

#include <vector>
#include <iostream>

namespace mysparky::graphics
{
	Shader::Shader(const char * vertPath, const char * fragPath)
		: m_VertPath(vertPath), m_FragPath(fragPath)
	{
		m_ShaderID = load();
	}

	GLuint Shader::load()
	{
		GLuint program = glCreateProgram();
		GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

		const char* vertSource = read_file(m_VertPath).c_str();
		const char* fragSource = read_file(m_FragPath).c_str();

		glShaderSource(vertex, 1, &vertSource, NULL);
		glCompileShader(vertex);

		GLint result;
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(vertex, length, &length, &error[0]);
			std::cout << "Failed to compile vertex shader: " << &error[0] << std::endl;
			glDeleteShader(vertex);
			return -1;
		}

		glShaderSource(fragment, 1, &fragSource, NULL);
		glCompileShader(fragment);
		GLint result;
		glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(fragment, length, &length, &error[0]);
			std::cout << "failed to compile fragment shader: " << &error[0] << std::endl;
			glDeleteShader(fragment);
			return -1;
		}
	}

	Shader::~Shader()
	{
	}
	void Shader::enable() const
	{
	}
	void Shader::disable() const
	{
	}
}
