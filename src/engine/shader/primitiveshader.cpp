#include "primitiveshader.hpp"
#include "./lib/loadshaders.hpp"
#include "meshshader.hpp"

PrimitiveShader::PrimitiveShader(const char* v, const char* f)
    : vec(v), frag(f) {}
void PrimitiveShader::init() {
    programId = LoadShaders(vec, frag, &defines);
}
