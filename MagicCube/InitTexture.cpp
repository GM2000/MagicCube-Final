
#include "Render.h"

typedef struct
{
	//Í¼Æ¬³ß´ç
	int width, height;
	//Éî¶È
	int bit_depth;
	//Í¸Ã÷¶È
	int flag;

	//ÏñËØ
	GLubyte *rgba;
} pic_data;

std::vector<GLuint> TextureList;

int LoadPNG(char *filepath, pic_data *out);

void loadBlockTexture()
{
	pic_data PNGData;

	if (LoadPNG("Texture\\BlockTexture.png",&PNGData))
	{
		TextureList.resize(TextureList.size() + 1);

		glGenTextures(1, &TextureList[TextureList.size()-1]);

		glBindTexture(GL_TEXTURE_2D, TextureList[TextureList.size() - 1]);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, PNGData.width, PNGData.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, PNGData.rgba);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	}
}
void initTexture()
{
	loadBlockTexture();
}