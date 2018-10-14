#pragma once
#include <iostream>
#include "src\graphics\window.h"
#include "src\maths\Maths.h"
#include "src\graphics\Shader.h"
#include "src\graphics\buffers\Buffer.h"
#include "src\graphics\buffers\IndexBuffer.h"
#include "src\graphics\buffers\VertexArray.h"

using namespace mysparky;
using namespace graphics;
using namespace maths;
using std::cout;
using std::endl;

int main()
{
	Window window("MySparkyWindow", 960, 540);
	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
#if 0
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
#else	
	//TODO check if using SPAN is better here
	GLfloat vertices[] =
	{
		0, 0, 0,
		0, 3, 0,
		8, 3, 0,
		8, 0, 0
	};

	GLushort indices[] =
	{
		0,1,2,
		2,3,0
	};
	GLfloat colorsA[] =
	{
		1.0f,0.0f,1.0f,1.0f,
		1.0f,0.0f,1.0f,1.0f,
		1.0f,0.0f,1.0f,1.0f,
		1.0f,0.0f,1.0f,1.0f
	};

	GLfloat colorsB[] =
	{
		0.2f,0.3f,0.8f,1.0f,
		0.2f,0.3f,0.8f,1.0f,
		0.2f,0.3f,0.8f,1.0f,
		0.2f,0.3f,0.8f,1.0f
	};
	VertexArray sprite1, sprite2;
	std::unique_ptr<Buffer> vbo1(new Buffer(vertices, 4 * 3, 3));
	std::unique_ptr<Buffer> vbo2(new Buffer(vertices, 4 * 3, 3));
	IndexBuffer ibo(indices, 6);

	sprite1.AddBuffer(vbo1.get(), 0);
	sprite1.AddBuffer(new Buffer(colorsA, 4 * 4, 4), 1);
	sprite2.AddBuffer(vbo2.get(), 0);
	sprite2.AddBuffer(new Buffer(colorsB, 4 * 4, 4), 1);
#endif

	Mat4 ortho = Mat4::Orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.Enable();

	shader.SetUniformMat4("pr_matrix", ortho);
	shader.SetUniformMat4("ml_matrix", Mat4::Translation(Vec3(4, 3, 0)));

	shader.SetUniform2f("inLight_pos", Vec2(4.0f, 1.5f));

	shader.SetUniform4f("inColor", Vec4(1.0f, 1.0f, .5f, 1.0f));

	while (!window.Closed())
	{
		window.Clear();
		double x, y;
		window.GetMousePosition(x, y);
		shader.SetUniform2f("inLight_pos", Vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
#if 0 
		glDrawArrays(GL_TRIANGLES, 0, 6);
#else
		sprite1.Bind();
		ibo.Bind();
		shader.SetUniformMat4("ml_matrix", Mat4::Translation(Vec3(4, 3, 0)));
		glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_SHORT, 0);
		sprite1.Unbind();
		ibo.Unbind();

		sprite2.Bind();
		ibo.Bind();
		shader.SetUniformMat4("ml_matrix", Mat4::Translation(Vec3(0, 0, 0)));
		glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_SHORT, 0);
		sprite2.Unbind();
		ibo.Unbind();
#endif	
		window.Update();
	}
	window.Destroy();

	return 0;
}