#version 110

uniform mat4 baseTransform;
attribute vec3 position;
attribute vec2 uvs;
varying vec2 texCoord;
void main()
{
    gl_Position = baseTransform * vec4(position, 1.0);
    texCoord = uvs;
}
