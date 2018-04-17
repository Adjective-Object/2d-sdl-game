#version 150 core

uniform mat4 baseTransform;
in vec3 position;
void main()
{
    gl_Position = baseTransform * vec4(position, 1.0);
}
