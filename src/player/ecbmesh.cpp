#include "player/ecbmesh.hpp"
#include "engine/gl.h"
#include "player/ecb.hpp"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define assignValues(x, y) \
    {                      \
        out[i++] = x;      \
        out[i++] = y;      \
        out[i++] = -0.5;   \
    }

void updateMeshToEcb(Ecb& e, GLfloat* out) {
    int i = 0;
    assignValues(0, 0);
    assignValues(e.widthLeft, 0);
    assignValues(0, e.heightBottom);

    assignValues(0, 0);
    assignValues(0, e.heightBottom);
    assignValues(-e.widthRight, 0);

    assignValues(0, 0);
    assignValues(-e.widthRight, 0);
    assignValues(0, -e.heightTop);

    assignValues(0, 0);
    assignValues(0, -e.heightTop);
    assignValues(e.widthLeft, 0);
}

void fillMeshColors(glm::vec3 color, GLfloat* out) {
    for (size_t i = 0; i < 36; i += 3) {
        out[i] = color.x;
        out[i + 1] = color.y;
        out[i + 2] = color.z;
    }
}

void EcbMesh::init(Ecb& e) {
    updateMeshToEcb(e, vectorBuffer);
    fillMeshColors(glm::vec3(212 / 255.0f, 112 / 255.0f, 95 / 255.0f),
                   colorBuffer);
    WorldspaceMesh::init(vectorBuffer, colorBuffer, NULL, 12);
}

void EcbMesh::update(Ecb& e) {
    updateMeshToEcb(e, vectorBuffer);

    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, num_points * 3 * sizeof(GLfloat),
                 vectorBuffer, GL_STATIC_DRAW);
}
