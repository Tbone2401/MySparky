#pragma once

#include "glew.h";

namespace mysparky::graphics
{
	class Buffer
	{
	public:
		Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
		~Buffer();
		
		void Bind() const;
		void Unbind() const;

		GLuint GetComponentCount() const { return m_ComponentCount; }
	private:
		GLuint m_BufferID;
		GLuint m_ComponentCount;
	};
}
