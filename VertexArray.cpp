//
// Created by Binh Nguyen Thanh on 17/4/26.
//

#include "VertexArray.h"

#include "GL/glew.h"

VertexArray::VertexArray(const float* verts, unsigned int numVerts,
    const unsigned int* indices, unsigned int numIndices)
    :mNumVerts(numVerts)
    ,mNumIndices(numIndices) {
    // Create vertex array
    glGenVertexArrays(1, &mVertexArrayID);
    glBindVertexArray(mVertexArrayID);

    // Create vertex buffer
    glGenBuffers(1, &mVertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, numVerts * 8 * sizeof(float), verts, GL_STATIC_DRAW);

    // Create an index buffer
    glGenBuffers(1, &mIndexBufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    // Specify the vertex attributes
    // (For now, assume one vertex format)
    // Position is 3 floats
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0);
    // Normal is 3 floats
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
        reinterpret_cast<void*>(sizeof(float) * 3));
    // Texture coordinates is 2 floats
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float),
        reinterpret_cast<void*>(sizeof(float) * 6));
}

VertexArray::~VertexArray()
{
    glDeleteBuffers(1, &mVertexBufferID);
    glDeleteBuffers(1, &mIndexBufferID);
    glDeleteVertexArrays(1, &mVertexArrayID);
}

void VertexArray::SetActive() {
    glBindVertexArray(mVertexArrayID);
}
