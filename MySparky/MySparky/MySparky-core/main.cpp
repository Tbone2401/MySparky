#include <iostream>
#include "src\graphics\window.h"
#include "src\maths\Vec2.h"

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

	Vec2 vec = Vec2(1.0f, 2.0f);
	vec = vec + vec;
	cout << vec << endl;


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