#include "Application.h"
#include "ModuleProgram.h"
#include "SDL.h"
#include "glew-2.1.0/include/GL/glew.h"

ModuleProgram::ModuleProgram()
{
}

// Destructor
ModuleProgram::~ModuleProgram()
{
}

// Called before render is available
bool ModuleProgram::Init()
{
	vertex_source = LoadShaderSource("default_vertex.glsl");
	fragment_source = LoadShaderSource("default_fragment.glsl");

	//vertex_id = CompileShader(GL_VERTEX_SHADER, vertex_source);
	//GLuint fragment = CompileShader(GL_FRAGMENT_SHADER, fragment_source);

	program = glCreateProgram();

	//glAttachShader(program, vertex);
	//glAttachShader(program, fragment);

	//glLinkProgram(program);
	//glLinkProgram(program);

	return true;
}

update_status ModuleProgram::PreUpdate()
{
	return UPDATE_CONTINUE;
}

// Called every draw update
update_status ModuleProgram::Update()
{

	return UPDATE_CONTINUE;
}

update_status ModuleProgram::PostUpdate()
{

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleProgram::CleanUp()
{
	LOG("Destroying program");
	glDeleteProgram(program);

	return true;
}

char* ModuleProgram::LoadShaderSource(const char* shader_file_name)
{
	char* data = nullptr;
	FILE* file = nullptr;
	fopen_s(&file, shader_file_name, "rb");
	if (file)
	{
		fseek(file, 0, SEEK_END);
		int size = ftell(file);
		data = (char*)malloc(size + 1);
		fseek(file, 0, SEEK_SET);
		fread(data, 1, size, file);
		data[size] = 0;
		fclose(file);
	}
	return data;
}

unsigned ModuleProgram::CompileShader(unsigned type, const char* source)
{
	unsigned shader_id = glCreateShader(type);
	glShaderSource(shader_id, 1, &source, 0);
	glCompileShader(shader_id);
	int res = GL_FALSE;
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &res);
	if (res == GL_FALSE)
	{
		int len = 0;
		glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &len);
		if (len > 0)
		{
			int written = 0;
			char* info = (char*)malloc(len);
			glGetShaderInfoLog(shader_id, len, &written, info);
			LOG("Log Info: %s", info);
			free(info);
		}
	}
	return shader_id;
}

