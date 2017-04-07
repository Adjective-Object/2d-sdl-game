#version 110

uniform sampler2D ambientTexture;
varying vec2 texCoord;
void main()
{
    vec4 texColor = texture2D(ambientTexture, texCoord);
    gl_FragColor = vec4(0.1,0,0,1) + texColor;
}

