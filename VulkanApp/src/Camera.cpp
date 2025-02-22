#include "Camera.h"
#include <iostream>

void Camera::Update(float deltaTime)
{
    if (!Input::IsMouseButtonDown(Input::RightClick))
    {
        Input::ShowMouse();
        return;
    }
    else Input::HideMouse();

    glm::vec2 mouseDelta = Input::GetMouseDelta();
    m_Yaw -= mouseDelta.x / m_Sensitivity;
    m_Pitch += mouseDelta.y / m_Sensitivity;

    if (Input::IsKeyPressed(Input::LeftShift)) m_Speed = 5.0f;
    if (Input::IsKeyReleased(Input::LeftShift)) m_Speed = 1.0f;

    if (Input::IsKeyDown(Input::W)) m_Velocity.z = -m_Speed;
    if (Input::IsKeyDown(Input::S)) m_Velocity.z = m_Speed;
    if (Input::IsKeyDown(Input::A)) m_Velocity.x = -m_Speed;
    if (Input::IsKeyDown(Input::D)) m_Velocity.x = m_Speed;
    if (Input::IsKeyDown(Input::A)) m_Velocity.x = -m_Speed;
    if (Input::IsKeyDown(Input::E)) m_Velocity.y = m_Speed;
    if (Input::IsKeyDown(Input::Q)) m_Velocity.y = -m_Speed;

    glm::mat4 cameraRotation = GetRotationMatrix();
    m_Position += glm::vec3(cameraRotation * glm::vec4(m_Velocity * deltaTime, 0.0f));

    //std::cout << m_Position.x << " " << m_Position.y << " " << m_Position.z << " " << std::endl;
    //std::cout << m_Pitch << " " << m_Yaw << std::endl << std::endl;

    m_Velocity = glm::vec3(0.0f);
}

glm::mat4 Camera::GetView() const
{
    glm::mat4 cameraTranslation = glm::translate(glm::mat4(1.0f), m_Position);
    glm::mat4 cameraRotation = GetRotationMatrix();
    return glm::inverse(cameraTranslation * cameraRotation);
}

glm::mat4 Camera::GetRotationMatrix() const
{
    glm::quat pitchRotation = glm::angleAxis(m_Pitch, glm::vec3(-1.0f, 0.0f, 0.0f));
    glm::quat yawRotation = glm::angleAxis(m_Yaw, glm::vec3(0.0f, 1.0f, 0.0f));

    return glm::toMat4(yawRotation) * glm::toMat4(pitchRotation);
}
