#version 330 core 

uniform sampler2D tex;
out vec4 fColor;
in vec2 vs_tex_coord;

void  main()  
{  
	fColor =texture(tex,vs_tex_coord); 
	
	if (fColor.a==0.0)
	{
		discard;
	}
}  