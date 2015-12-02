
#include "MagicCube.h"
#include <png.h>

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

int LoadPNG(char *filepath, pic_data *out)
{
	//open file
	FILE *pic_fp;
	pic_fp = fopen(filepath, "rb");
	if (pic_fp == NULL)
		return false;

	//PNG info
	png_structp png_ptr;
	png_infop   info_ptr;
	//check the file is PNG
	char        buf[4];
	int         temp;

	//read png
	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0);
	info_ptr = png_create_info_struct(png_ptr);

	setjmp(png_jmpbuf(png_ptr));

	//checking PNG
	temp = fread(buf, 1, 4, pic_fp);
	temp = png_sig_cmp((png_const_bytep)buf, (png_size_t)0, 4);

	if (temp != 0) return false;

	//read PNG
	rewind(pic_fp);
	png_init_io(png_ptr, pic_fp);
	png_read_png(png_ptr, info_ptr, PNG_TRANSFORM_EXPAND, 0);

	//PNG data
	int color_type, channels;

	//get PNG data
	channels = png_get_channels(png_ptr, info_ptr);
	out->bit_depth = png_get_bit_depth(png_ptr, info_ptr);
	color_type = png_get_color_type(png_ptr, info_ptr);

	int i, j;
	int size, pos = 0;

	//read PNG
	png_bytep* row_pointers;
	row_pointers = png_get_rows(png_ptr, info_ptr);
	out->width = png_get_image_width(png_ptr, info_ptr);
	out->height = png_get_image_height(png_ptr, info_ptr);

	//malloc
	size = out->width * out->height;
	size *= (4 * sizeof(GLubyte));

	out->rgba = (GLubyte*)malloc(size);

	//is malloc?
	if (out->rgba == NULL)
	{
		fclose(pic_fp);
		puts("[ERROR]:no memory!");
		return false;
	}

	//start to copy memory
	if (channels == 4 || color_type == PNG_COLOR_TYPE_RGB_ALPHA)//RGBA
	{
		out->flag = 1;

		temp = (4 * out->width);

		for (i = 0; i < out->height; i++)
		{
			for (j = 0; j < temp; j += 4)
			{
				out->rgba[0 + pos] = row_pointers[i][j];
				out->rgba[1 + pos] = row_pointers[i][j + 1];
				out->rgba[2 + pos] = row_pointers[i][j + 2];
				out->rgba[3 + pos] = row_pointers[i][j + 3];
				pos += 4;
			}
		}
	}
	else if (channels == 3 || color_type == PNG_COLOR_TYPE_RGB)//RGB
	{
		temp = (3 * out->width);

		for (i = 0; i < out->height; i++)
		{
			for (j = 0; j < temp; j += 3)
			{
				out->rgba[0 + pos] = row_pointers[i][j];
				out->rgba[1 + pos] = row_pointers[i][j + 1];
				out->rgba[2 + pos] = row_pointers[i][j + 2];
				out->rgba[3 + pos] = 255;
				pos += 4;
			}
		}
	}
	else return false;

	//free memory
	png_destroy_read_struct(&png_ptr, &info_ptr, 0);
	return true;
}