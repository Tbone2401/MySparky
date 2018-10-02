#pragma once

#include <glew.h>
#include "../utils/FileUtils.h"
#include "../maths/Maths.h"

namespace mysparky::graphics
{
	class Shader
	{
	private:
		GLuint m_ShaderID;
		const char* m_VertPath, *m_FragPath;
		GLuint load();
		GLint getUniformLocation(const GLchar* name) { return glGetUniformLocation(m_ShaderID, name); };
	public:
		Shader(const char* vertPath, const char* fragPath);
		~Shader();


		void SetUniform1f(const GLchar* name, const float value) { glUniform1f(getUniformLocation(name), value); };
		void SetUniform1i(const GLchar* name, const int value)             { glUniform1i(getUniformLocation(name), value); };
		void SetUniform2f(const GLchar* name, const maths::Vec2& vector)   { glUniform2f(getUniformLocation(name), vector.m_X, vector.m_Y); };
		void SetUniform3f(const GLchar* name, const maths::Vec3& vector)   { glUniform3f(getUniformLocation(name), vector.m_X, vector.m_Y, vector.m_Z); };
		void SetUniform4f(const GLchar* name, const maths::Vec4& vector)   { glUniform4f(getUniformLocation(name), vector.m_X, vector.m_Y, vector.m_Z, vector.m_W); };
		void SetUniformMat4(const GLchar* name, const maths::Mat4& matrix) { glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.m_Elements);};

		void Enable() const;
		void Disable() const;
	};
}