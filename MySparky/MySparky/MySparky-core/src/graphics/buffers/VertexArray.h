#pragma once
#include <vector>
#include "glew.h";

#include "Buffer.h"

namespace mysparky::graphics
{
	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();
		void AddBuffer(Buffer* buffer, GLuint index);
		void Bind() const;
		void Unbind() const;
	private:
		GLuint m_ArrayID;
		std::vector<Buffer*> m_Buffers;
	};
}