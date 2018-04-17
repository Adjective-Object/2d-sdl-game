#version 150 core

uniform sampler2D ambientTexture;
in vec2 texCoord;
out vec4 fragColor;
void main()
{
    vec4 texColor = texture(ambientTexture, texCoord);
    fragColor = vec4(0.1,0,0,1) + texColor;
}

