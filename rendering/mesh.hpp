#pragma once
#define STB_IMAGE_IMPLEMENTATION
#include <vector>
#include <glm/glm.hpp>
#include <GL/glew.h>
#include "stb_image.h"
#include <stdio.h>
#include "common.hpp"
template <typename vertex>
class Mesh
{
    unsigned int vao, vbo, ibo, tex;
    
public:
    std::vector<vertex> vertices;
    std::vector<unsigned int> indices;

    ~Mesh()
    {
        unbind();
        glDeleteTextures(1, &tex);
    }

    void unbind(void)
    {
        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void update(void)
    {
        for (auto it = vertices.begin(); it!=vertices.end(); ++it)
            it->pos.x += 0.01f;
        glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size()*sizeof(vertex), &vertices[0]);
    }

protected:
    Mesh(const std::vector<vertex>& vertices, const std::vector<unsigned int>& indices)
        : vertices(vertices), indices(indices) 
    {
        // load textures
        int width, height, bpp;
        unsigned char* tex_data;

        stbi_set_flip_vertically_on_load(true);
        
        tex_data = stbi_load(TEXTURE_PATH, &width, &height, &bpp, 4);
    
        glGenTextures(1, &tex);
        glBindTexture(GL_TEXTURE_2D, tex);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, tex_data);
        //glBindTexture(GL_TEXTURE_2D, 0);

        if (tex_data)
            stbi_image_free(tex_data);
        
        // create and bind vertex array object
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        // create and bind vertex buffer
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(vertex), &vertices[0], GL_DYNAMIC_DRAW);

        // create, bind and initialize index buffer
        glGenBuffers(1, &ibo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
    }
};