#include <windows.h>    // MUST be first for GL definitions
#include "Application.h"
#include <GLFW/glfw3.h>

namespace Engine {

    // internal engine state
    static GLFWwindow* s_Window = nullptr;
    static float s_ScrollDelta = 0.0f;

    Application::Application() {}
    Application::~Application() {}

    void Application::ScrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
        s_ScrollDelta = (float)yoffset;
    }

    bool Application::IsMouseButtonPressed(int button) {
        if (!s_Window) return false;
        auto state = glfwGetMouseButton(s_Window, button);
        return state == GLFW_PRESS;
    }

    float Application::GetScrollDelta() {
        return s_ScrollDelta;
    }

    void Application::GetMousePosition(float& x, float& y) {
        if (!s_Window) return;
        double xpos, ypos;
        glfwGetCursorPos(s_Window, &xpos, &ypos);

        // convert pixel space to OpenGL space (-1.0 to 1.0)
        x = (float)((xpos / 1280.0) * 2.0 - 1.0);
        y = (float)(1.0 - (ypos / 720.0) * 2.0);
    }

    void Application::Run() {
        if (!glfwInit()) return;

        s_Window = glfwCreateWindow(1280, 720, "My Engine", NULL, NULL);
        if (!s_Window) {
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(s_Window);
        glfwSetScrollCallback(s_Window, Application::ScrollCallback);

        while (!glfwWindowShouldClose(s_Window) && m_Running) {
            s_ScrollDelta = 0.0f; // scroll every frame
            glfwPollEvents();

            glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            Update(); // run game logic
            Render(); // run game drawing

            // default triangle for testing
            glBegin(GL_TRIANGLES);
            glColor3f(1.f, 0.f, 0.f); glVertex2f(-0.5f, -0.5f);
            glColor3f(0.0f, 1.f, 0.0f); glVertex2f(0.5f, -0.5f);
            glColor3f(0.0f, 0.0f, 1.f); glVertex2f(0.0f, 0.5f);
            glEnd();

            glfwSwapBuffers(s_Window);
        }
        glfwTerminate();
    }
}