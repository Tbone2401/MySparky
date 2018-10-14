#version 330 core

layout (location = 0) out vec4 color;

uniform vec4 inColor;
uniform vec2 inLight_pos;

in DATA
{
	vec4 position;
	vec4 color;
} fs_in;

in vec4 pos;

void main()
{
	float intensity = 1.0 / length(fs_in.position.xy - inLight_pos);
	color = fs_in.color * intensity;
}