#version 110

attribute vec3 position;
attribute vec3 vertexColor;
varying vec3 fragmentColor;
uniform mat4 baseTransform;
void main()
{
    fragmentColor = vertexColor;
    gl_Position = baseTransform * vec4(position, 1.0);
}
