//
// Created by Binh Nguyen Thanh on 17/4/26.
//

#ifndef _SHADER_H
#define _SHADER_H
#include <GL/glew.h>

#include "Math.h"


class Shader {
public:
    Shader();
    ~Shader();

    bool Load(const char* vertexPath, const char* fragmentPath);
    void Unload();
    void SetActive();

    void SetMatrixUniform(const char* name, const Matrix4& matrix);
private:
    bool CompileShader(const char* fileName, GLuint shaderType, GLuint& outShader);
    bool IsCompiled(GLuint shader);
    bool IsValidProgram();

    GLuint mVertexShader;
    GLuint mFragmentShader;
    GLuint mShaderProgram;
};


#endif //_SHADER_H