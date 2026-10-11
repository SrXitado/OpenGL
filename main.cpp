#include <glad/glad.h>
#include <glfw/glfw3.h> 
#include <iostream>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void debug();

int main()
{

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    debug();

    glViewport(-0.5, -0.5, 1280, 720);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    glfwTerminate();

    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void debug() {
    glfwSetErrorCallback([](int code, const char* desc) {
        std::cout << "GLFW error " << code << ": " << desc << std::endl;
        });

    if (!glfwInit()) {
        std::cout << "glfwInit failed" << std::endl;
        return;
    }

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))   // 2) só depois o GLAD
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }
}