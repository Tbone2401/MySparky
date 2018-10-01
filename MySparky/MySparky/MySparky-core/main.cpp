#pragma once
#include <iostream>
#include "src\graphics\window.h"
#include "src\maths\Maths.h"
#include "src\utils\FileUtils.h"

using namespace mysparky;
using namespace graphics;
using namespace maths;
using std::cout;
using std::endl;

int main()
{
	Window window("MySparkyWindow", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	cout << _MSC_VER << endl;

	Vec2 vec = Vec2(1.0f, 2.0f);
	Vec2 vec2 = Vec2(2.0f, 2.0f);
	vec = vec;
	cout << (vec != vec2) << endl;

	Mat4 position = Mat4::Translation(Vec3(2, 3, 4));
	Vec4 column = position.m_Columns[3];

	std::string file = read_file("main.cpp");
	cout << file << endl;

	while (!window.Closed())
	{
		window.Clear();
		if (window.IsMouseBtnPressed(GLFW_MOUSE_BUTTON_LEFT))
		{
			cout << window.GetCursorPositionX() << ", " << window.GetCursorPositionY() << endl;
		}
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

		//glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		window.Update();
	}
	window.Destroy();

	system("Pause");
	return 0;
}