#include "Application.h"
#include <windows.h>
#include <GLFW/glfw3.h>

class MyGame : public Engine::Application {
public:
    

    void Update() override {
        
    }

    void Render() override {
        // draw the static triangle at the center of the screen
        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f); glVertex2f(-0.5f, -0.5f);
        glColor3f(0.f, 1.f, 0.f); glVertex2f(0.5f, -0.5f);
        glColor3f(0.f, 0.f, 1.f); glVertex2f(0.0f, 0.5f);
        glEnd();
    }
};

int main() {
    MyGame game;
    game.Run();
    return 0;
}