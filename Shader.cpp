//
// Created by Binh Nguyen Thanh on 17/4/26.
//

#include "Shader.h"

#include <fstream>
#include <sstream>
#include <SDL3/SDL.h>
#include <GL/glew.h>

Shader::Shader() : mVertexShader(0), mFragmentShader(0), mShaderProgram(0) {
}

Shader::~Shader()
{
}
bool Shader::Load(const char *vertexPath, const char *fragmentPath) {
    if (!CompileShader(vertexPath, GL_VERTEX_SHADER, mVertexShader)||
        !CompileShader(fragmentPath, GL_FRAGMENT_SHADER, mFragmentShader)) {
        return false;
    }

    mShaderProgram = glCreateProgram();
    glAttachShader(mShaderProgram, mVertexShader);
    glAttachShader(mShaderProgram, mFragmentShader);
    glLinkProgram(mShaderProgram);

    if (!IsValidProgram()) {
        return false;
    }
    return true;
}

void Shader::Unload() {
    glDeleteProgram(mShaderProgram);
    glDeleteShader(mVertexShader);
    glDeleteShader(mFragmentShader);
}

void Shader::SetActive() {
    glUseProgram(mShaderProgram);
}

void Shader::SetMatrixUniform(const char *name, const Matrix4 &matrix) {
    GLint location = glGetUniformLocation(mShaderProgram, name);

    glUniformMatrix4fv(
        location,
        1,
        GL_TRUE,
        matrix.GetAsFloatPtr()
    );
}

bool Shader::CompileShader(const char *fileName, GLuint shaderType, GLuint& outShader){
    std::ifstream shaderFile(fileName);
    if (shaderFile.is_open()) {
        std::stringstream sstream;
        sstream << shaderFile.rdbuf();
        std::string contents = sstream.str();
        const char* contentsChar = contents.c_str();

        outShader = glCreateShader(shaderType);
        glShaderSource(outShader, 1, &contentsChar, NULL);
        glCompileShader(outShader);

        if (!IsCompiled(outShader)) {
            SDL_Log("Failed to compile shader: %s", fileName);
            return false;
        }
    } else {
        SDL_Log("Shader file not found: %s", fileName);
        return false;
    }
    return true;
}

bool Shader::IsCompiled(GLuint shader)
{
    GLint status;
    // Query the compile status
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

    if (status != GL_TRUE)
    {
        char buffer[512];
        memset(buffer, 0, 512);
        glGetShaderInfoLog(shader, 511, nullptr, buffer);
        SDL_Log("GLSL Compile Failed:\n%s", buffer);
        return false;
    }

    return true;
}

bool Shader::IsValidProgram() {
    GLint status;
    // Query the compile status
    glGetProgramiv(mShaderProgram, GL_LINK_STATUS, &status);

    if (status != GL_TRUE)
    {
        char buffer[512];
        memset(buffer, 0, 512);
        glGetProgramInfoLog(mShaderProgram, 511, nullptr, buffer);
        SDL_Log("Program Compile Failed:\n%s", buffer);
        return false;
    }

    return true;
}


