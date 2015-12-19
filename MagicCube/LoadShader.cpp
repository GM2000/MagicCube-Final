
#include "Shader.h"

std::vector<shader> Shader;
std::vector<GLuint> UniformLocation;

typedef struct
{
	GLenum       type;
	const char*  filename;
	GLuint       shader;
} shaderInfo;

static const GLchar* readShader(const char* filename)
{
#ifdef WIN32
	FILE* infile;
	fopen_s(&infile, filename, "rb");
#else
	FILE* infile = fopen(filename, "rb");
#endif

	if (!infile)
	{
#ifdef _DEBUG
		std::cerr << "[ERROR]:Unable to open file '" << filename << "'" << std::endl;
#endif 
		return NULL;
	}

	fseek(infile, 0, SEEK_END);
	int len = ftell(infile);
	fseek(infile, 0, SEEK_SET);

	GLchar* source = new GLchar[len + 1];

	fread(source, 1, len, infile);
	fclose(infile);

	source[len] = 0;

	return const_cast<const GLchar*>(source);
}
GLuint loadShaders(shaderInfo* shaders)
{
	if (shaders == NULL) 
		return 0;

	GLuint program = glCreateProgram();

	shaderInfo* entry = shaders;

	while (entry->type != GL_NONE)
	{
		GLuint shader = glCreateShader(entry->type);

		entry->shader = shader;

		const GLchar* source = readShader(entry->filename);
		if (source == NULL) {
			for (entry = shaders; entry->type != GL_NONE; ++entry) {
				glDeleteShader(entry->shader);
				entry->shader = 0;
			}

			return 0;
		}

		glShaderSource(shader, 1, &source, NULL);
		delete[] source;

		glCompileShader(shader);

		GLint compiled;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
		if (!compiled) {
#ifdef _DEBUG
			GLsizei len;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);

			GLchar* log = new GLchar[len + 1];
			glGetShaderInfoLog(shader, len, &len, log);
			std::cerr << "[ERROR]:Shader compilation failed: " << log << std::endl;
			delete[] log;
#endif

			return 0;
		}

		glAttachShader(program, shader);

		++entry;
	}

#ifdef GL_VERSION_4_1
	if (GLEW_VERSION_4_1)
	{
		//glProgramParameteri( program, GL_PROGRAM_SEPARABLE, GL_TRUE );
	}
#endif
	glLinkProgram(program);

	GLint linked;
	glGetProgramiv(program, GL_LINK_STATUS, &linked);
	if (!linked) {
#ifdef _DEBUG
		GLsizei len;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);

		GLchar* log = new GLchar[len + 1];
		glGetProgramInfoLog(program, len, &len, log);
		std::cerr << "[ERROR]:Shader linking failed: " << log << std::endl;
		delete[] log;
#endif

		for (entry = shaders; entry->type != GL_NONE; ++entry) {
			glDeleteShader(entry->shader);
			entry->shader = 0;
		}

		return 0;
	}

	return program;
}

void initShader()
{
	shaderInfo  Normail_3D_Shader[] = {
		{ GL_VERTEX_SHADER, "GLSL\\Normail3D.vert" },
		{ GL_FRAGMENT_SHADER, "GLSL\\Normail3D.frag" },
		{ GL_NONE, NULL } };

	Shader.push_back(shader(loadShaders(Normail_3D_Shader), normail3DUse,5));
	GLuint ProgramID = Shader[Shader.size() - 1].ProgramID;

	UniformLocation.push_back(glGetUniformLocation(ProgramID, "Frustum"));
	UniformLocation.push_back(glGetUniformLocation(ProgramID, "Rotate"));
	UniformLocation.push_back(glGetUniformLocation(ProgramID, "Translate"));
}