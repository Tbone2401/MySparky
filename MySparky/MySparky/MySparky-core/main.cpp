#include <iostream>
#include "src\graphics\window.h"
#include "main.h"

using namespace mysparky;
using namespace graphics;
using std::cout;
using std::endl;

int main()
{
	Window window("MySparkyWindow", 960, 540);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.Closed())
	{
		window.Clear();
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