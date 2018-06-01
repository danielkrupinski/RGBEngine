#version 460 core

out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D texture1;

void main(void)
{
	FragColor = texture(texture1, TexCoord);
}
