#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

struct Camera
{
public:
	Camera()
	{
	}

	void initisaliseCamera(const glm::vec3& position, float fov, float aspect, float nearClip, float farClip) // creates camera
	{
		this->position = position;
		this->forward = glm::vec3(0.0f, 0.0f, 1.0f);
		this->up = glm::vec3(0.0f, 1.0f, 0.0f);
		this->projection = glm::perspective(fov, aspect, nearClip, farClip);
	}

	glm::vec3 getPosition() //getter
	{
		return this->position;
	}

	inline glm::mat4 GetViewProjection() const //getter
	{
		return projection * glm::lookAt(position, position + forward, up);
	}

	void MoveForward(float amt) //allows forward movement
	{
		position += forward * amt;
	}

	void MoveRight(float amt) // allows movement to the right
	{
		position += glm::cross(up, forward) * amt;
	}

	void Pitch(float angle) // allows the camera to pitch
	{
		glm::vec3 right = glm::normalize(glm::cross(up, forward));

		forward = glm::vec3(glm::normalize(glm::rotate(angle, right) * glm::vec4(forward, 0.0)));
		up = glm::normalize(glm::cross(forward, right));
	}

	void RotateY(float angle) // rotates the camera
	{
		static const glm::vec3 UP(0.0f, 1.0f, 0.0f);

		glm::mat4 rotation = glm::rotate(angle, UP);

		forward = glm::vec3(glm::normalize(rotation * glm::vec4(forward, 0.0)));
		up = glm::vec3(glm::normalize(rotation * glm::vec4(up, 0.0)));
	}

protected:
private:
	glm::mat4 projection;
	glm::vec3 position;
	glm::vec3 forward;
	glm::vec3 up;
};


