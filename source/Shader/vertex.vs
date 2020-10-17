#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

uniform float xOffset;

out vec3 ourColor; // 向片段着色器输出一个颜色
out vec4 ourVertex;

void main()
{
   //gl_Position = vec4(aPos.x + xOffset, -aPos.y, aPos.z, 1.0);
   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
   ourColor = aColor;
   ourVertex = gl_Position;
}
