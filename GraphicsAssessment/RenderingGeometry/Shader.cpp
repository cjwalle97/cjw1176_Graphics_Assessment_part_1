#include "Shader.h"



Shader::Shader()
{
}


Shader::~Shader()
{
}

void Shader::Bind()
{
	glUseProgram(m_program);
}

void Shader::Unbind()
{
	glUseProgram(0);
}

//loads a File with the name of the inputed constant chararacter pointer and then runs it the inputed type of Shader
void Shader::load(const char * filename, unsigned int type)
{
	std::string line, contents;
	std::ifstream in(filename);

	while (std::getline(in, line))
	{
		contents += line + "\n";
	}

	const char* data = contents.c_str();

	switch (type)
	{
	case GL_FRAGMENT_SHADER:
	{
		const char* fsSource = "#version 410\n \
		in vec4 vColor;\
		out vec4 fragColor;\
		void main() {fragColor = vColor}";
	}

	case GL_VERTEX_SHADER:
	{
		const char* fsSource = "#version 410\n \
		in vec4 vColor;\
		out vec4 vertColor;\
		void main() {vertColor = vColor}";
	}
	}
}

void Shader::attach()
{
	m_program = glCreateProgram();
	glAttachShader(m_program, m_vertexShader);
	glAttachShader(m_program, m_fragmentShader);
	glLinkProgram(m_program);

	int success = GL_FALSE;
	glGetProgramiv(m_program, GL_LINK_STATUS, &success);
	if (success == GL_FALSE)
	{
		int infoLogLength = 0;
		glGetProgramiv(m_program, GL_INFO_LOG_LENGTH, &infoLogLength);
		char* infoLog = new char[infoLogLength];
		glGetProgramInfoLog(m_program, infoLogLength, 0, infoLog);
		printf("Error: Failed to link shader program!\n");
		printf("%s\n", infoLog);
		delete[] infoLog;
	}
	glDeleteShader(m_fragmentShader);
	glDeleteShader(m_vertexShader);
}

void Shader::defaultLoad()
{
		/* Create Shaders */
	m_vsSource = "#version 410\n \
							layout(location=0) in vec4 position; \
							layout(location=1) in vec4 color; \
							out vec4 vColor; \
							uniform mat4 projectionViewWorld; \
							void main() { vColor = color; gl_Position = projectionViewWorld * position; }";

	m_fsSource = "#version 410\n \
							in vec4 vColor; \
							out vec4 fragColor; \
							void main() { fragColor = vColor; }";

		/* Compile Shaders */
	m_vertexShader = glCreateShader(GL_VERTEX_SHADER);
	m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(m_vertexShader, 1, (const char **)&m_vsSource, 0);
	glCompileShader(m_vertexShader);
	glShaderSource(m_fragmentShader, 1, (const char **)&m_fsSource, 0);
	glCompileShader(m_fragmentShader);
}

unsigned int Shader::getUniform(const char* name)
{
	return glGetUniformLocation(m_program, name);
}
