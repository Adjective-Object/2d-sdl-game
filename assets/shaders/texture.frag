#version 150 core

uniform sampler2D ambientTexture;
in vec2 texCoord;
out vec4 fragColor;
void main()
{
    vec4 texColor = texture(ambientTexture, texCoord);
    vec4 uvColor = vec4(1, texCoord.x, texCoord.y, 1);
    fragColor = texColor;
}

