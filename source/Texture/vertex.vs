#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexcoord;

uniform float xOffset;

out vec3 ourColor; // 向片段着色器输出一个颜色
out vec2 outTexcoord;

void main()
{
   gl_Position = vec4(aPos.x + xOffset, aPos.y, aPos.z, 1.0);
   ourColor = aColor;
   outTexcoord = aTexcoord;
}
