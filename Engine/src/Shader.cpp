#include <Amethyst/Logging.hpp>
#include <Amethyst/Shader.hpp>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

using namespace Amethyst;

Shader::Shader(const char *vShaderPath, const char *fShaderPath) {
    std::string vShaderString;
    std::string fShaderString;

    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        vShaderFile.open(vShaderPath);
        fShaderFile.open(fShaderPath);

        std::stringstream vShaderStream;
        std::stringstream fShaderStream;

        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();

        vShaderString = vShaderStream.str();
        fShaderString = fShaderStream.str();
    } catch (std::ifstream::failure &) {
        SERVER_ERROR("ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ");
    }

    const char *vShaderSource = vShaderString.c_str();
    const char *fShaderSource = fShaderString.c_str();

    int success;
    std::array<char, 1024> infoLog{};

    unsigned int vShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader, 1, &vShaderSource, nullptr);
    glCompileShader(vShader);

    glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vShader, infoLog.max_size(), nullptr, infoLog.data());
        SERVER_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED");
        SERVER_ERROR("{}", infoLog.data());
    }

    unsigned int fShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader, 1, &fShaderSource, nullptr);
    glCompileShader(fShader);

    glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fShader, infoLog.max_size(), nullptr, infoLog.data());
        SERVER_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED");
        SERVER_ERROR("{}", infoLog.data());
    }

    mID = glCreateProgram();
    glAttachShader(mID, vShader);
    glAttachShader(mID, fShader);
    glLinkProgram(mID);

    glGetProgramiv(mID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(mID, infoLog.max_size(), nullptr, infoLog.data());
        SERVER_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED");
        SERVER_ERROR("{}", infoLog.data());
    }

    glDeleteShader(vShader);
    glDeleteShader(fShader);
}

void Shader::Use() const {
    glUseProgram(mID);
}

void Shader::SetBool(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(mID, name.c_str()), (int) value);
}

void Shader::SetInt(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(mID, name.c_str()), value);
}

void Shader::SetFloat(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(mID, name.c_str()), value);
}

unsigned int Shader::GetID() const {
    return mID;
}
