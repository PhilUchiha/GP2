#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "camera.h"

struct Transform
{
public:
	Transform(const glm::vec3& position = glm::vec3(), const glm::vec3& rotation = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f))
	{
		this->position = position;
		this->rotation = rotation;
		this->scale = scale;
	}

	inline glm::mat4 GetModel() const  //gets model information
	{
		glm::mat4 posMat = glm::translate(position);
		glm::mat4 scaleMat = glm::scale(scale);
		glm::mat4 rotX = glm::rotate(rotation.x, glm::vec3(1.0, 0.0, 0.0));
		glm::mat4 rotY = glm::rotate(rotation.y, glm::vec3(0.0, 1.0, 0.0));
		glm::mat4 rotZ = glm::rotate(rotation.z, glm::vec3(0.0, 0.0, 1.0));
		glm::mat4 rotMat = rotX * rotY * rotZ;

		return posMat * rotMat * scaleMat; //returns matrixes
	}

	inline glm::mat4 GetMVP(const Camera& camera) const //getter for model view projection matrix
	{
		glm::mat4 VP = camera.GetViewProjection(); //gets view projection matrixc
		glm::mat4 M = GetModel(); //gets model

		return VP * M;
		camera.GetViewProjection() * GetModel(); //creates view prokection matrix
	}

	inline glm::vec3* GetPosition() { return &position; } //getters
	inline glm::vec3* GetRotation() { return &rotation; }
	inline glm::vec3* GetScale() { return &scale; }

	inline void SetPosition(glm::vec3& position) { this->position = position; } // setters
	inline void SetRotation(glm::vec3& rotation) { this->rotation = rotation; }
	inline void SetScale(glm::vec3& scale) { this->scale = scale; }
protected:
private:
	glm::vec3 position; //posiition variable
	glm::vec3 rotation; //rotation variable
	glm::vec3 scale; //scale variable
};


