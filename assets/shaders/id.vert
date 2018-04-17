#version 150 core

in vec3 position;
in vec3 vertexColor;
out vec3 fragmentColor;
uniform mat4 baseTransform;
void main()
{
    fragmentColor = vertexColor;
    gl_Position = baseTransform * vec4(position, 1.0);
}
