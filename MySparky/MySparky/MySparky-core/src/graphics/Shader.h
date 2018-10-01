#pragma once

#include <glew.h>
#include "../utils/FileUtils.h"

namespace mysparky::graphics
{
	class Shader
	{
	private:
		GLuint m_ShaderID;
		const char* m_VertPath, *m_FragPath;
		GLuint load();
	public:
		Shader(const char* vertPath, const char* fragPath);
		~Shader();

		void enable() const;
		void disable() const;
	};
}