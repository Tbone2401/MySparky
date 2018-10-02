#pragma once
#include <iostream>
#include "src\graphics\window.h"
#include "src\maths\Maths.h"
#include "src\graphics\Shader.h"

using namespace mysparky;
using namespace graphics;
using namespace maths;
using std::cout;
using std::endl;

int main()
{
	Window window("MySparkyWindow", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	//WARNING UGLY TEST CODE AHEAD
	GLfloat vertices[] =
	{
		 0, 0, 0,
		 8, 0, 0,
		 0, 3, 0,		 
		 0, 3, 0,
		 8, 3, 0,
		 8, 0, 0
	};
	GLuint vbo;

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	Mat4 ortho = Mat4::Orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.Enable();

	shader.SetUniformMat4("pr_matrix", ortho);
	shader.SetUniformMat4("ml_matrix", Mat4::Rotation(45.0f, Vec3(0,0,1)));

	while (!window.Closed())
	{
		window.Clear();
		glDrawArrays(GL_TRIANGLES, 0, 6);
		window.Update();
	}
	window.Destroy();

	return 0;
}