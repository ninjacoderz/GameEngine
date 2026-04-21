//
// Created by Binh Nguyen Thanh on 17/4/26.
//

#ifndef _VERTEXARRAY_H
#define _VERTEXARRAY_H


class VertexArray {
public:
    VertexArray(const float *verts, unsigned int numVerts, const unsigned int *indices, unsigned int numIndices);
    ~VertexArray();
    void SetActive();

    unsigned int GetNumIndices() const { return mNumIndices; };
    unsigned int GetNumVerts() const { return mNumIndices; };

private:
    unsigned int mNumVerts;
    unsigned int mNumIndices;

    unsigned int mVertexBufferID;
    unsigned int mIndexBufferID;
    unsigned int mVertexArrayID;
};


#endif //_VERTEXARRAY_H
