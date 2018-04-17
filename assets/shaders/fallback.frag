#version 150 core
// fallback shader for making things deadly pink
// used when no useable material information is found on models
out vec4 fragColor;
void main()
{
    fragColor = vec4(1, 0, 1, 1);
}

