#version 110
// fallback shader for making things deadly pink
// used when no useable material information is found on models

void main()
{
    gl_FragColor = vec4(1, 0, 1, 1);
}

