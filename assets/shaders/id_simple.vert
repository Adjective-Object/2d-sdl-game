#version 110

uniform mat4 baseTransform;
attribute vec3 position;
void main()
{
    gl_Position = baseTransform * vec4(position, 1.0);
}
