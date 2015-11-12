#version 330 core  

layout(location = 0) in  vec4 in_position;
layout(location = 1) in  vec2 in_tex_coord;

out vec2 vs_tex_coord;

void  main()  
{  
	vs_tex_coord = in_tex_coord;
	gl_Position = in_position;  
}  