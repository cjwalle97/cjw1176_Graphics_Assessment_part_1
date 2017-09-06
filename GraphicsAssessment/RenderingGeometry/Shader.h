#pragma once

#include "mesh.h"
#include <imgui.h>
#include <imgui_impl_glfw_gl3.h>


class Shader
{
public:
	Shader();
	~Shader();
	void bind();
	void unbind();
	void load(const char * filename, unsigned int type);
	void attach();
	void defaultLoad();
	unsigned int getUniform(const char *);

	unsigned int m_vertexShader;
	unsigned int m_fragmentShader;
	const char* vsSource;
	const char* fsSource;
	

private:
	unsigned int m_program;
};