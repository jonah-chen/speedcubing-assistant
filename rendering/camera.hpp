#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera
{
    glm::mat4 perspective;
    glm::vec3 pos;
    glm::vec3 fwd;
    glm::vec3 up;

public:
    Camera(const glm::vec3& pos, float fov, float aspect, float z_near, float z_far)
    {
        perspective = glm::perspective(fov, aspect, z_near, z_far);
        this->pos = pos;
        fwd = glm::vec3(0.7071f, 0, 0.7071f);
        up = glm::vec3(0,1,0);
    }

    inline glm::mat4 get_view_projection() const 
    { 
        return perspective * glm::lookAt(pos, pos + fwd, up);
    }

    inline void move_up()
    {
        pos.y += 0.01f;
        pos.z -= 0.01f;
    }
};