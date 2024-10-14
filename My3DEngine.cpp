#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <chrono>
#include "GraphMaths.h"
#include "Poligon.h"
#include "Model3D.h"
#include "Rgb.h"



int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "My3DEngine", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    std::cout << glGetString(GL_VENDOR) << std::endl;
    std::cout << glGetString(GL_RENDERER) << std::endl;
    std::cout << glGetString(GL_VERSION) << std::endl;

    


    Model3D cube = Model3D::BuildCube();
    InitProyectionMatrix(SCREEN_WIDTH, SCREEN_HEIGHT, Z_NEAR, Z_FAR, FOV);
    auto lastTime = std::chrono::high_resolution_clock::now();
    //Bucle de renderizado
    while (!glfwWindowShouldClose(window))
    {
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsedTime = currentTime - lastTime;
        cube.Draw(elapsedTime.count(), true, false, true);

        glfwSwapBuffers(window);
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
    }

    glfwTerminate();
    return 0;
}