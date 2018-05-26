#pragma once
#include "RenderEngine.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <SOIL/SOIL.h>

class Mesh 
{
	public:
		Mesh::Mesh(GLfloat *vertices, unsigned int *indices, unsigned int sizeVertices, unsigned int sizeIndices);
		Mesh::~Mesh();
		void Draw();
	private:
		GLuint VAO, VBO, EBO, shaderProgram;
		unsigned int sizeIndices;
};


