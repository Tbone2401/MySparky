#pragma once

#include "glew.h";

namespace mysparky::graphics
{
	class IndexBuffer
	{
	public:
		IndexBuffer(GLushort *data, GLsizei count);
		~IndexBuffer();
		void Bind() const;
		void Unbind() const;

		inline GLuint GetCount() const { return m_Count; }
	private:
		GLuint m_BufferID;
		GLuint m_Count;
	};
}
