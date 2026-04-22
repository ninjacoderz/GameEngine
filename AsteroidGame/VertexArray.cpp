//
// Created by Binh Nguyen Thanh on 17/4/26.
//

#include "VertexArray.h"

#include "GL/glew.h"

VertexArray::VertexArray(const float *verts, unsigned int numVerts, const unsigned int *indices,
                         unsigned int numIndices) {

    glGenVertexArrays(1, &mVertexArrayID);
    glBindVertexArray(mVertexArrayID);

    // Vertext Buffer
    glGenBuffers(1, &mVertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferID);
    glBufferData(
        GL_ARRAY_BUFFER, // The active buffer type to write to
        numVerts * 5 * sizeof(float), // Number of bytes to copy
        verts, // Source to copy from (pointer)
        GL_STATIC_DRAW // How will we use this data?
    );

    // Index Buffer
    glGenBuffers(1, &mIndexBufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBufferID);
    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        numIndices * sizeof(unsigned int),
        indices,GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
        0, // Attribute index (0 for first one)
        3, // Number of components (3 in this case)
        GL_FLOAT, // Type of the components
        GL_FALSE, // (Only used for integral types)
        sizeof(float) * 5, // Stride (usually size of each vertex)
        0 // Offset from start of vertex to this attribute
    );

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(
        1,
        2,
        GL_FLOAT,
        GL_FALSE,
        sizeof(float) * 5,
        reinterpret_cast<void*>(sizeof(float) * 3));
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
