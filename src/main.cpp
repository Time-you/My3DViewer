#include <glad/glad.h>          // Glad підключається раніше за GLFW
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>

int main()
{
    // Приклад використання GLM
    glm::vec3 vector(1.0f, 0.0f, 0.0f);
    std::cout << "Vector: (" << vector.x << ", " << vector.y << ", " << vector.z << ")\n";

    // Ініціалізація GLFW
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW!\n";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(800, 600, "My3DViewer", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window!\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Завантаження функцій OpenGL через Glad
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::cerr << "Failed to initialize Glad!\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << "\n";

    // Головний цикл: заливка фону, вихід по Esc або закриттю вікна
    while (!glfwWindowShouldClose(window))
    {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GLFW_TRUE);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
