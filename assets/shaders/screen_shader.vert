#version 110

uniform vec2 screenDimensions;
attribute vec2 pixelPosition;
attribute vec2 uvs;
varying vec2 texCoord;
void main()
{
    vec2 fracPosition = vec2(2, 2) * pixelPosition / screenDimensions;
    gl_Position = vec4(
            -1.0 + fracPosition.x,
            1.0 - fracPosition.y,
            0,
            1.0);

    texCoord = uvs;
}

