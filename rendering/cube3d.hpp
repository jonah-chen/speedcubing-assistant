// 2D cube
#pragma once

#include <vector>
#include "common.hpp"
#include "camera.hpp"
#include "shader.hpp"
#include "mesh.hpp"
#include "cube.hpp"

namespace cube3d
{
    constexpr float V_POSITIONS[] {
        RIGHT_VERTEX_POS, LEFT_VERTEX_POS, FRONT_VERTEX_POS, BACK_VERTEX_POS, DOWN_VERTEX_POS, UP_VERTEX_POS
    };

    struct vertex
    {
        glm::vec3 pos;
        glm::vec2 tex_coord;

        vertex(float x, float y, float z, float s, float t)
            : pos(glm::vec3(x, y, z)), tex_coord(glm::vec2(s, t)) {}
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
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (const void*)offsetof(vertex, pos));
            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (const void*)offsetof(vertex, tex_coord));
        }
    };

    std::vector<vertex> _DBG_white_cube()
    {
        std::vector<vertex> vertices;
        for (int i = 0; i < 6; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                int t = 12*(i * 9 + j);
                vertices.push_back(vertex(V_POSITIONS[t],V_POSITIONS[t+1],V_POSITIONS[t+2],_WHITE_L, _WHITE_U));
                vertices.push_back(vertex(V_POSITIONS[t+3],V_POSITIONS[t+4],V_POSITIONS[t+5],_WHITE_L, _WHITE_D));
                vertices.push_back(vertex(V_POSITIONS[t+6],V_POSITIONS[t+7],V_POSITIONS[t+8],_WHITE_R, _WHITE_U));
                vertices.push_back(vertex(V_POSITIONS[t+9],V_POSITIONS[t+10],V_POSITIONS[t+11],_WHITE_R, _WHITE_D));
            }
        }
        return vertices;
    }



    std::vector<unsigned int> IBO {
        UP_INDICES, RIGHT_INDICES, FRONT_INDICES
    }; 
}