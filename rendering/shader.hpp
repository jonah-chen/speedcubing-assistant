#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>


class Shader 
{
    unsigned int program;
    mutable std::unordered_map<const char*, int> u_cache;
public:
    Shader(const char* _vertex_shader, const char* _fragment_shader)
    {
        program = glCreateProgram();
        unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
        unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
        
        char *vs, *fs;
        int vsize, fsize;
        FILE *_vs, *_fs;

        _vs = fopen(_vertex_shader, "r");
        _fs = fopen(_fragment_shader, "r");
        fseek(_vs, 0, SEEK_END);
        fseek(_fs, 0, SEEK_END);
        vsize = ftell(_vs);
        fsize = ftell(_fs);
        vs = (char*)malloc(vsize);
        fs = (char*)malloc(fsize);
        rewind(_vs);    
        rewind(_fs);
        fread(vs, 1, vsize, _vs);
        fread(fs, 1, fsize, _fs);
        fclose(_vs);
        fclose(_fs);

        glShaderSource(vertex_shader, 1, &vs, &vsize);
        glShaderSource(fragment_shader, 1, &fs, &fsize);
        glCompileShader(vertex_shader);
        glCompileShader(fragment_shader);

        glAttachShader(program, vertex_shader);
        glAttachShader(program, fragment_shader);
        glLinkProgram(program);
        glValidateProgram(program);

        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);
        free(vs);
        free(fs);

        bind();
    }
    
    ~Shader()
    {
        glDeleteProgram(program);
    }

    inline void bind(void) const
    {
        glUseProgram(program);
    }

    inline void unbind(void) const
    {
        glUseProgram(0);
    }


    int locate(const char* u_name) const
    {
        if (u_cache.find(u_name) != u_cache.end())
            return u_cache.at(u_name);

        int loc = glGetUniformLocation(program, u_name);
        if (loc >= 0)
            u_cache[u_name] = loc;
        else
            printf("uniform %s does not exist\n", u_name);

        return loc;
    }

    // mat4
    inline void set_uniform(const char* u_name, glm::mat4 data, GLboolean transpose=GL_FALSE) { glUniformMatrix4fv(locate(u_name), 1, transpose, glm::value_ptr(data)); }

    // vec4
    inline void set_uniform(const char* u_name, glm::vec4 data) { glUniform4f(locate(u_name), data.x, data.y, data.z, data.w); }
    inline void set_uniform(const char* u_name, float x, float y, float z, float w) { glUniform4f(locate(u_name), x, y, z, w); }

    // vec3
    inline void set_uniform(const char* u_name, glm::vec3 data) { glUniform3f(locate(u_name), data.x, data.y, data.z); }
    inline void set_uniform(const char* u_name, float x, float y, float z) { glUniform3f(locate(u_name), x, y, z); }
    
    // vec2
    inline void set_uniform(const char* u_name, glm::vec2 data) { glUniform2f(locate(u_name), data.x, data.y); }
    inline void set_uniform(const char* u_name, float x, float y) { glUniform2f(locate(u_name), x, y); }

    // float
    inline void set_uniform(const char* u_name, float x) { glUniform1f(locate(u_name), x); }
    
    // int
    inline void set_uniform(const char* u_name, int x) { glUniform1i(locate(u_name), x); }

};