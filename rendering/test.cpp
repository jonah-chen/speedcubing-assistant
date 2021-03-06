// clang++ test.cpp -I /usr/local/include/GLFW -L /usr/local/lib -lglfw3 -lpthread -lm -lz -lGL -lX11 -lXext -lXfixes -ldl -lGLEW

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#include "camera.hpp"
#include "mesh.hpp"
#include "shader.hpp"
#include "cube3d.hpp"

static void error_checking(GLenum source,
            GLenum type,
            GLuint id,
            GLenum severity,
            GLsizei length,
            const GLchar *message,
            const void *userParam)
{
    printf("type: %u, id: %u, sev: %u\nmsg:%s", type, id, severity, message);
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1920, 1080, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        return -1;

    printf("%s\n", glGetString(GL_VERSION));

    glDebugMessageCallback(error_checking, nullptr);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glfwSwapInterval(1);

    Cube c;
    c.U();
    c.U();
    c.U();
    Shader shader ("./vertexshader.glsl", "./fragmentshader.glsl");
    Camera camera (glm::vec3(-5,0,-5), 70.0f, 4.0f/3.0f, 0.01f, 1000.0f);
    cube3d::Mesh mesh (cube3d::vertices_from_cube(c), cube3d::IBO(camera.get_pos()));

    shader.set_uniform("u_texture", 0);
    
    
    /* Loop until the user closes the window */
    
    double lastTime;
    
    while (!glfwWindowShouldClose(window))
    {
        lastTime = glfwGetTime();
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT); // clear window

        // mesh.update();

        shader.set_uniform("u_mvp", camera.get_view_projection());
        // shader.set_uniform("u_color", 0.8f, 0.1f, 0.3f, 0.4f);
        camera.move_up();

        glDrawElements(GL_TRIANGLES, 648, GL_UNSIGNED_INT, nullptr);


        /* bench frame time */
        printf("\r%.3lfms/f", 1000*(glfwGetTime()-lastTime));
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    printf("\n");
    return 0;
}