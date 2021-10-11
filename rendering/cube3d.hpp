// 2D cube
#pragma once

#include <vector>
#include "common.hpp"
#include "camera.hpp"
#include "shader.hpp"
#include "mesh.hpp"
#include "../common/cube.hpp"

namespace cube3d
{
    constexpr float V_POSITIONS[] {
        UP_VERTEX_POS, 
        LEFT_VERTEX_POS, 
        FRONT_VERTEX_POS,
        DOWN_VERTEX_POS, 
        RIGHT_VERTEX_POS, 
        BACK_VERTEX_POS
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

    std::vector<vertex> vertices_from_cube(const Cube& cube)
    {
        int t;
        const uint8_t* data = cube.get_data();
        std::vector<vertex> vertices;
        vertices.reserve(54);
        for (int i = 0; i < 54; ++i)
        {
            t = i*12;
            switch (data[i])
            {
            case WHITE:
                vertices.push_back(vertex(V_POSITIONS[t],V_POSITIONS[t+1],V_POSITIONS[t+2],_WHITE_L, _WHITE_U));
                vertices.push_back(vertex(V_POSITIONS[t+3],V_POSITIONS[t+4],V_POSITIONS[t+5],_WHITE_L, _WHITE_D));
                vertices.push_back(vertex(V_POSITIONS[t+6],V_POSITIONS[t+7],V_POSITIONS[t+8],_WHITE_R, _WHITE_U));
                vertices.push_back(vertex(V_POSITIONS[t+9],V_POSITIONS[t+10],V_POSITIONS[t+11],_WHITE_R, _WHITE_D));
                break;
            case YELLOW:
                vertices.push_back(vertex(V_POSITIONS[t],V_POSITIONS[t+1],V_POSITIONS[t+2],_YELLOW_L, _YELLOW_U));
                vertices.push_back(vertex(V_POSITIONS[t+3],V_POSITIONS[t+4],V_POSITIONS[t+5],_YELLOW_L, _YELLOW_D));
                vertices.push_back(vertex(V_POSITIONS[t+6],V_POSITIONS[t+7],V_POSITIONS[t+8],_YELLOW_R, _YELLOW_U));
                vertices.push_back(vertex(V_POSITIONS[t+9],V_POSITIONS[t+10],V_POSITIONS[t+11],_YELLOW_R, _YELLOW_D));
                break;
            case ORANGE:
                vertices.push_back(vertex(V_POSITIONS[t],V_POSITIONS[t+1],V_POSITIONS[t+2],_ORANGE_L, _ORANGE_U));
                vertices.push_back(vertex(V_POSITIONS[t+3],V_POSITIONS[t+4],V_POSITIONS[t+5],_ORANGE_L, _ORANGE_D));
                vertices.push_back(vertex(V_POSITIONS[t+6],V_POSITIONS[t+7],V_POSITIONS[t+8],_ORANGE_R, _ORANGE_U));
                vertices.push_back(vertex(V_POSITIONS[t+9],V_POSITIONS[t+10],V_POSITIONS[t+11],_ORANGE_R, _ORANGE_D));
                break;
            case RED:
                vertices.push_back(vertex(V_POSITIONS[t],V_POSITIONS[t+1],V_POSITIONS[t+2],_RED_L, _RED_U));
                vertices.push_back(vertex(V_POSITIONS[t+3],V_POSITIONS[t+4],V_POSITIONS[t+5],_RED_L, _RED_D));
                vertices.push_back(vertex(V_POSITIONS[t+6],V_POSITIONS[t+7],V_POSITIONS[t+8],_RED_R, _RED_U));
                vertices.push_back(vertex(V_POSITIONS[t+9],V_POSITIONS[t+10],V_POSITIONS[t+11],_RED_R, _RED_D));
                break;
            case GREEN:
                vertices.push_back(vertex(V_POSITIONS[t],V_POSITIONS[t+1],V_POSITIONS[t+2],_GREEN_L, _GREEN_U));
                vertices.push_back(vertex(V_POSITIONS[t+3],V_POSITIONS[t+4],V_POSITIONS[t+5],_GREEN_L, _GREEN_D));
                vertices.push_back(vertex(V_POSITIONS[t+6],V_POSITIONS[t+7],V_POSITIONS[t+8],_GREEN_R, _GREEN_U));
                vertices.push_back(vertex(V_POSITIONS[t+9],V_POSITIONS[t+10],V_POSITIONS[t+11],_GREEN_R, _GREEN_D));
                break;
            case BLUE:
                vertices.push_back(vertex(V_POSITIONS[t],V_POSITIONS[t+1],V_POSITIONS[t+2],_BLUE_L, _BLUE_U));
                vertices.push_back(vertex(V_POSITIONS[t+3],V_POSITIONS[t+4],V_POSITIONS[t+5],_BLUE_L, _BLUE_D));
                vertices.push_back(vertex(V_POSITIONS[t+6],V_POSITIONS[t+7],V_POSITIONS[t+8],_BLUE_R, _BLUE_U));
                vertices.push_back(vertex(V_POSITIONS[t+9],V_POSITIONS[t+10],V_POSITIONS[t+11],_BLUE_R, _BLUE_D));
                break;
            default:
                throw "Unknown Color is on the cube";
            }
        }
        return vertices;
    }

    std::vector<vertex> _DBG_white_cube()
    {
        std::vector<vertex> vertices;
        vertices.reserve(54);
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

    std::vector<unsigned int> IBOo {
        UP_INDICES, RIGHT_INDICES, FRONT_INDICES
    }; 

    // the back of the index buffer is rendered last

    std::vector<unsigned int> IBO(float x, float y, float z)
    {
        return IBOo;
    }

    inline std::vector<unsigned int> IBO(const glm::vec3& pos)
    {
        return IBO(pos.x, pos.y, pos.z);
    }
    
}