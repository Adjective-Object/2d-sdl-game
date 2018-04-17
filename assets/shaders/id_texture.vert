#version 150 core

uniform mat4 baseTransform;
in vec3 position;
in vec2 uvs;
out vec2 texCoord;
void main()
{
    gl_Position = baseTransform * vec4(position, 1.0);
    texCoord = uvs;
}
