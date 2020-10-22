#version 330 core

in vec3 ourColor;
in vec2 outTexcoord;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;

out vec4 FragColor;

void main()
{
	float scale = 4.0f;

	vec4 color1 = texture(ourTexture1, outTexcoord);
	vec4 color2 = texture(ourTexture2, vec2(0.5 - 1.0 / (scale * 2.0) + outTexcoord.x / scale, 0.5 - 1.0 / (scale * 2.0) + outTexcoord.y / scale));

   FragColor =  mix(color1, color2, 0.5);
   //FragColor = texture(ourTexture2, outTexcoord);
   //FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}

