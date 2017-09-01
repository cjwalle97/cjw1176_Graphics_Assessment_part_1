#pragma once
#include "Application.h"
#include "gl_core_4_4.h"
#include <GLFW\glfw3.h>
#include <stdio.h>
#include <assert.h>
#include <glm\vec3.hpp>
#include <glm\vec2.hpp>
#include <glm\glm.hpp>
#include <glm\ext.hpp>
#include <iostream>

using glm::vec3;
using glm::vec4;
using glm::mat4;

#pragma once
class GeometryApp :
	public Application
{
private:
	unsigned int m_VAO;
	unsigned int m_VBO;
	unsigned int m_IBO;
	unsigned int m_programID;
	mat4 m_projectionViewMatrix;
	struct Vertex
	{
		vec4 position;
		vec4 color;
	};
public:
	GeometryApp();
	~GeometryApp();
	virtual void generateGrid(unsigned int rows, unsigned int columns) {}
	virtual void startup(int a, int b) {}
	virtual void shutdown() {}
	virtual void draw() {}
	virtual void update() {}
};