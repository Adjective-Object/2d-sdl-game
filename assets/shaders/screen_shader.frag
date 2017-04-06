#version 110

uniform sampler2D ambientTexture;
varying vec2 texCoord;
void main()
{
    vec4 texColor = texture2D(ambientTexture, texCoord);
    vec4 uvColor = vec4(1, texCoord.x, texCoord.y, 1);
    gl_FragColor = 0.5 * texColor + 0.5 * uvColor;
}

