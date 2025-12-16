#pragma once

// forward declaration to avoid needing glfw3.h in the header
struct GLFWwindow;

namespace Engine {

    class Application {
    public:
        Application();
        virtual ~Application();

        void Run();

        // input for later
        static bool IsMouseButtonPressed(int button);
        static void GetMousePosition(float& x, float& y);
        static float GetScrollDelta();

        // functions to be overridden by the Sandbox
        virtual void Update() {}
        virtual void Render() {}

    private:
        bool m_Running = true;

        //  must be static to work with GLFW's C-style interface
        static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
    };

}