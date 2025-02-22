#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

namespace Input 
{

enum Key
{
    A = GLFW_KEY_A,
    B = GLFW_KEY_B,
    C = GLFW_KEY_C,
    D = GLFW_KEY_D,
    E = GLFW_KEY_E,
    F = GLFW_KEY_F,
    G = GLFW_KEY_G,
    H = GLFW_KEY_H,
    I = GLFW_KEY_I,
    J = GLFW_KEY_J,
    K = GLFW_KEY_K,
    L = GLFW_KEY_L,
    M = GLFW_KEY_M,
    N = GLFW_KEY_N,
    O = GLFW_KEY_O,
    P = GLFW_KEY_P,
    Q = GLFW_KEY_Q,
    R = GLFW_KEY_R,
    S = GLFW_KEY_S,
    T = GLFW_KEY_T,
    U = GLFW_KEY_U,
    V = GLFW_KEY_V,
    W = GLFW_KEY_W,
    X = GLFW_KEY_X,
    Y = GLFW_KEY_Y,
    Z = GLFW_KEY_Z,
    Space = GLFW_KEY_SPACE,
    Escape = GLFW_KEY_ESCAPE,
    Enter = GLFW_KEY_ENTER,
    LeftShift = GLFW_KEY_LEFT_SHIFT,
    RightShift = GLFW_KEY_RIGHT_SHIFT,
    LeftCtrl = GLFW_KEY_LEFT_CONTROL,
    RightCtrl = GLFW_KEY_RIGHT_CONTROL,
    LeftAlt = GLFW_KEY_LEFT_ALT,
    RightAlt = GLFW_KEY_RIGHT_ALT,
    Up = GLFW_KEY_UP,
    Down = GLFW_KEY_DOWN,
    Left = GLFW_KEY_LEFT,
    Right = GLFW_KEY_RIGHT,
    Num0 = GLFW_KEY_0,
    Num1 = GLFW_KEY_1,
    Num2 = GLFW_KEY_2,
    Num3 = GLFW_KEY_3,
    Num4 = GLFW_KEY_4,
    Num5 = GLFW_KEY_5,
    Num6 = GLFW_KEY_6,
    Num7 = GLFW_KEY_7,
    Num8 = GLFW_KEY_8,
    Num9 = GLFW_KEY_9
};

enum MouseButton
{
    LeftClick = GLFW_MOUSE_BUTTON_LEFT,
    RightClick = GLFW_MOUSE_BUTTON_RIGHT,
    MiddleClick = GLFW_MOUSE_BUTTON_MIDDLE,
    // Button4 = GLFW_MOUSE_BUTTON_4,
    // Button5 = GLFW_MOUSE_BUTTON_5,
    // Button6 = GLFW_MOUSE_BUTTON_6,
    // Button7 = GLFW_MOUSE_BUTTON_7,
    // Button8 = GLFW_MOUSE_BUTTON_8
};

void CreateInputDevices(GLFWwindow* window);

bool IsKeyPressed(Key key);
bool IsKeyDown(Key key);
bool IsKeyReleased(Key key);

bool IsMouseButtonPressed(MouseButton btn);
bool IsMouseButtonDown(MouseButton btn);
bool IsMouseButtonReleased(MouseButton btn);

glm::vec2 GetMousePosition();
glm::vec2 GetMouseDelta();

void HideMouse();
void ShowMouse();

}