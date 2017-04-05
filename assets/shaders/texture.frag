#version 110

uniform sampler2D ambientTexture;
varying vec2 texCoord;
void main()
{
    vec4 tex = texture2D(ambientTexture, texCoord);
    gl_FragColor = vec4(tex.rgb, 1.0);
}

