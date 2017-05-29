#include "meshshader.hpp"
#include "primitiveshader.hpp"
#include "./lib/loadshaders.hpp"

PrimitiveShader::PrimitiveShader(const char* v, const char* f)
    : vec(v), frag(f) {}
void PrimitiveShader::init() {
    programId = LoadShaders(vec, frag, &defines);
}
