#pragma once

#define GLM_FORCE_RADIANS
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include "Input.h"

class Camera
{
public:
	Camera() = default;
	void Update(float deltaTime);
	glm::mat4 GetView() const;
	glm::mat4 GetRotationMatrix() const;

private:
	glm::vec3 m_Velocity{ 0.0f };
	glm::vec3 m_Position{ 2.0f, 2.0f, 2.0f };

	float m_Pitch = 30.5f;
	float m_Yaw   = 2.5f;

	float m_Speed = 1.0f;
	float m_Sensitivity = 400.0f;
};