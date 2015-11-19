#version 330 core  

uniform mat4 Frustum;

layout(location = 0) in  vec4 in_position;

void  main()  
{  
	gl_Position = in_position * Frustum;  
}  