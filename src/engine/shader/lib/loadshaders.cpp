#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "engine/gl.h"

// cribbed from
// http://www.opengl-tutorial.org/beginners-tutorials/tutorial-2-the-first-triangle/

std::string REQUIRE_STRING = "// @require";

std::string templateCode(std::string VertexShaderCode,
                         const std::map<std::string, std::string>* defines) {
    // insert defines
    if (defines != NULL) {
        bool anyChanges = false;
        for (std::pair<std::string, std::string> define : *defines) {
            std::string requireString = REQUIRE_STRING + " " + define.first;

            // try to find a place in the code where the @require
            // definitions occurs w/o being a substring of another
            // @require block
            size_t insertionPoint = 0;
            bool foundMatch = false;
            while (insertionPoint != (size_t)-1 &&
                   insertionPoint < VertexShaderCode.length() && !foundMatch) {
                insertionPoint =
                    VertexShaderCode.find(requireString, insertionPoint);
                size_t nextChar = insertionPoint + requireString.length();
                if (VertexShaderCode[nextChar] == ' ' ||
                    VertexShaderCode[nextChar] == '\r' ||
                    VertexShaderCode[nextChar] == '\n') {
                    foundMatch = true;
                } else if (insertionPoint != -1) {
                    insertionPoint++;
                }
            }

            if (!foundMatch) {
                continue;
            }

            if (insertionPoint != ((size_t)-1)) {
                anyChanges = true;
                size_t insertionLength =
                    VertexShaderCode.find("\n", insertionPoint) -
                    insertionPoint;
                std::string DefineString =
                    "#define " + define.first + " " + define.second;
                std::cout << DefineString << std::endl;
                VertexShaderCode = VertexShaderCode.replace(
                    insertionPoint, insertionLength, DefineString);
            }
        }

        if (anyChanges) {
            std::cout << "Templated vertex code:" << std::endl;
            int i = 1;
            bool newline = true;
            for (char c : VertexShaderCode) {
                if (newline) {
                    printf("%3d : ", i);
                    i++;
                    newline = false;
                }
                if (c == '\n') {
                    newline = true;
                }
                std::cout << c;
            }
            std::cout << std::endl;
        }
    }

    return VertexShaderCode;
}

GLuint LoadShaders(const char* vertex_file_path,
                   const char* fragment_file_path,
                   const std::map<std::string, std::string>* defines) {
    // Create the shaders
    GLuint VertexShaderID = _glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = _glCreateShader(GL_FRAGMENT_SHADER);

    // Read the Vertex Shader code from the file
    std::string VertexShaderCode;
    std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
    if (VertexShaderStream.is_open()) {
        std::string Line = "";
        while (getline(VertexShaderStream, Line))
            VertexShaderCode += "\n" + Line;
        VertexShaderStream.close();
    } else {
        printf(
            "Impossible to open %s. Are you in the right directory ? Don't "
            "forget to read the FAQ !\n",
            vertex_file_path);
        getchar();
        return 0;
    }

    VertexShaderCode = templateCode(VertexShaderCode, defines);

    // Read the Fragment Shader code from the file
    std::string FragmentShaderCode;
    std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
    if (FragmentShaderStream.is_open()) {
        std::string Line = "";
        while (getline(FragmentShaderStream, Line))
            FragmentShaderCode += "\n" + Line;
        FragmentShaderStream.close();
    }

    GLint Result = GL_FALSE;
    int InfoLogLength;

    // Compile Vertex Shader
    printf("Compiling shader : %s\n", vertex_file_path);
    char const* VertexSourcePointer = VertexShaderCode.c_str();
    _glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
    _glCompileShader(VertexShaderID);

    // Check Vertex Shader
    _glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    _glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (Result == GL_FALSE || InfoLogLength > 0) {
        std::vector<char> VertexShaderErrorMessage(InfoLogLength + 1);
        _glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL,
                           &VertexShaderErrorMessage[0]);
        printf("%s\n", &VertexShaderErrorMessage[0]);
    }

    // Compile Fragment Shader
    printf("Compiling shader : %s\n", fragment_file_path);
    char const* FragmentSourcePointer = FragmentShaderCode.c_str();
    _glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
    _glCompileShader(FragmentShaderID);

    // Check Fragment Shader
    _glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    _glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (Result == GL_FALSE || InfoLogLength > 0) {
        std::vector<char> FragmentShaderErrorMessage(InfoLogLength + 1);
        _glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL,
                           &FragmentShaderErrorMessage[0]);
        printf("%s\n", &FragmentShaderErrorMessage[0]);
    }

    // Link the program
    printf("Linking program\n");
    GLuint ProgramID = _glCreateProgram();
    _glAttachShader(ProgramID, VertexShaderID);
    _glAttachShader(ProgramID, FragmentShaderID);
    _glLinkProgram(ProgramID);

    // Check the program
    _glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    _glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
        _glGetProgramInfoLog(ProgramID, InfoLogLength, NULL,
                            &ProgramErrorMessage[0]);
        printf("%s\n", &ProgramErrorMessage[0]);
    }

    _glDetachShader(ProgramID, VertexShaderID);
    _glDetachShader(ProgramID, FragmentShaderID);

    _glDeleteShader(VertexShaderID);
    _glDeleteShader(FragmentShaderID);

    return ProgramID;
}
