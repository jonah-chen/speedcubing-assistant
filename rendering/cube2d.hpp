// 2D cube
#pragma once

#include "common.hpp"
#include "camera.hpp"
#include "shader.hpp"
#include "mesh.hpp"

namespace cube2d
{
    struct vertex
    {
        glm::vec2 pos;
        glm::vec2 tex_coord;

        vertex(float x, float y, float s, float t)
            : pos(glm::vec2(x, y)), tex_coord(glm::vec2(s, t)) {}
    };

    class Mesh : public ::Mesh<vertex>
    {
    public:
        Mesh(const std::vector<vertex>& vertices, const std::vector<unsigned int>& indices)
            : ::Mesh<vertex>(vertices, indices)
        {
            // set vertex attributes
            glEnableVertexAttribArray(0);
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (const void*)offsetof(vertex, pos));
            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (const void*)offsetof(vertex, tex_coord));
        }
    };
}