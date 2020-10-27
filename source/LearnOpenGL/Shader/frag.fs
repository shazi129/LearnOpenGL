#version 330 core

in vec3 ourColor;
in vec4 ourVertex;

out vec4 FragColor;

void main()
{
   FragColor = ourVertex;
}

