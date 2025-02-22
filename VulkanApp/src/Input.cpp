#include "Input.h"
#include <iostream>

#define MAX_KEYS 512

struct InputData
{
	GLFWwindow* Window = nullptr;

	// Input
	bool KeysPressed[MAX_KEYS]{ false };
	bool KeysDown[MAX_KEYS]{ false };
	bool KeysReleased[MAX_KEYS]{ false };

	// Mouse
	bool ButtonsPressed[3]{ false };
	bool ButtonsDown[3]{ false };
	bool ButtonsReleased[3]{ false };
	glm::vec2 MousePos{};
	glm::vec2 MouseDelta{};
};
static InputData s_InputData = {};

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
        glfwSetWindowShouldClose(window, true);
	
	if (key < MAX_KEYS)
    {
		s_InputData.KeysReleased[key] = ((action == GLFW_RELEASE) && s_InputData.KeysDown[key]);
		s_InputData.KeysDown[key] = action != GLFW_RELEASE;

		if (!s_InputData.KeysPressed[key])
			s_InputData.KeysPressed[key] = (action == GLFW_PRESS);
	}
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button >= 0 && button < 3)
	{
		s_InputData.ButtonsReleased[button] = ((action == GLFW_RELEASE) && s_InputData.ButtonsDown[button]);
		s_InputData.ButtonsDown[button] = (action != GLFW_RELEASE);

		if (!s_InputData.ButtonsPressed[button])
			s_InputData.ButtonsPressed[button] = (action == GLFW_PRESS);
	}
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	s_InputData.MouseDelta = { 0.0f, 0.0f };
	s_InputData.MouseDelta = glm::vec2{ xpos, ypos } - s_InputData.MousePos;
	s_InputData.MousePos = { xpos, ypos };
}

namespace Input
{

void CreateInputDevices(GLFWwindow* window)
{
	s_InputData.Window = window;

	glfwSetKeyCallback(window, key_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
}

bool IsKeyPressed(Key key)
{
	if (key > MAX_KEYS) return false;

	bool result = s_InputData.KeysPressed[key];

	s_InputData.KeysPressed[key] = false;

	return result;
}

bool IsKeyDown(Key key)
{
	int keyCode = (int)key;
	if (keyCode > MAX_KEYS) return false;

	return s_InputData.KeysDown[keyCode];
}

bool IsKeyReleased(Key key)
{
	if (key > MAX_KEYS) return false;

	bool result = s_InputData.KeysReleased[key];
	s_InputData.KeysReleased[key] = false;

	return result;
}

bool IsMouseButtonPressed(MouseButton btn)
{
	if (btn > 3) return false;
	bool result = s_InputData.ButtonsPressed[btn];
	s_InputData.ButtonsPressed[btn] = false;
	return result;
}

bool IsMouseButtonDown(MouseButton btn)
{
	if (btn > 3) return false;

	return s_InputData.ButtonsDown[btn];
}

bool IsMouseButtonReleased(MouseButton btn)
{
	if (btn > 3) return false;
	bool result = s_InputData.ButtonsReleased[btn];
	s_InputData.ButtonsReleased[btn] = false;
	return result;
}

glm::vec2 GetMousePosition()
{
	return s_InputData.MousePos;
}

glm::vec2 GetMouseDelta()
{
	glm::vec2 delta = s_InputData.MouseDelta;
	s_InputData.MouseDelta = { 0.0f, 0.0f };
	return delta;
}

void HideMouse()
{
	glfwSetInputMode(s_InputData.Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void ShowMouse()
{
	glfwSetInputMode(s_InputData.Window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

}