#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "GLWindow.h"

using namespace  std;

void main()
{
	GLWindow window(800, 600, "hello world");
	window.show();
}