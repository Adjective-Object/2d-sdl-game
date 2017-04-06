#version 110

uniform vec2 screenDimensions;
attribute vec3 pixelPosition;
attribute vec2 uvs;
varying vec2 texCoord;
void main()
{
    vec2 fracPosition = pixelPosition.xy / screenDimensions;
    gl_Position = vec4(fracPosition, 1.0 , 1.0);
    texCoord = uvs;
}

