#pragma once
#include <glm\glm.hpp>
#include <GL\glew.h>
#include <string>
#include "obj_loader.h"

struct Vertex
{
public:
	Vertex(const glm::vec3& position, const glm::vec2& texCoordinate)
	{
		this->position = position;
		this->texCoordinate = texCoordinate;
		this->normal = normal;
	}

	glm::vec3* GetPosition() { return &position; }
	glm::vec2* GetTexCoordinate() { return &texCoordinate; }
	glm::vec3* GetNormal() { return &normal; }

private:
	glm::vec3 position;
	glm::vec2 texCoordinate;
	glm::vec3 normal;
};

struct Sphere
{
public:

	Sphere(){}

	glm::vec3 GetPosition() { return position; }
	float GetRadius() { return radius; }

	void SetPosition(glm::vec3 pos)
	{
		this->position = pos;
	}

	void SetRadius(float radius)
	{
		this->radius = radius;
	}

private:
	glm::vec3 position;
	float radius;
};

class Mesh
{
public:
	Mesh();
	~Mesh();


	void draw();
	void initialise(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);
	void loadModel(const std::string& filename);
	void initialiseModel(const IndexedModel& model);
	void updateSphereData(glm::vec3 pos, float radius);
	glm::vec3 getSpherePosition() { return meshSphere.GetPosition(); }
	float getSphereRadius() { return meshSphere.GetRadius(); }

private:



	enum
	{
		POSITION_VERTEXBUFFER,
		TEXCOORD_VB,
		NORMAL_VB,
		INDEX_VB,
		NUM_BUFFERS
	};

	Sphere meshSphere;
	GLuint vertexArrayObject;
	GLuint vertexArrayBuffers[NUM_BUFFERS]; // create our array of buffers
	unsigned int drawCount; //how much of the vertexArrayObject do we want to draw
};